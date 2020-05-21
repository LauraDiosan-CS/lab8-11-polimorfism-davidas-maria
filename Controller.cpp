#include "Controller.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include <algorithm>
#include "RepoException.h"
#include "ValidationException.h"
#include "ReadFromFileException.h"

using namespace std;

Controller::Controller()
{
	this->repo = NULL;
}

Controller::Controller(RepoFile* repo)
{
	this->repo = repo;
}

Controller::~Controller()
{
	if (this->repo != NULL)
	{
		delete this->repo;
	}
}

vector<Resurse*> Controller::getAll()
{
	return this->repo->getAll();
}

Resurse* Controller::getResurseAtPosition(int pos) throw(RepoException)
{
	return this->repo->getResurse(pos);
}

void Controller::addResurseFinanciare(string nume, string data, double valuare, double nrExemplare, double durataViata)
throw(ValidationException, RepoException)
{
	ResurseFinanciare* rf = new ResurseFinanciare(nume, data, valuare, nrExemplare,durataViata);
	this->repo->addResurse(rf);
}

void Controller::addResurseMateriale(string nume, string data, double valuare, double moneda)
throw(ValidationException, RepoException)
{
	ResurseMateriale* rm = new ResurseMateriale(nume, data, valuare, moneda);
	this->repo->addResurse(rm);
}

void Controller::updateResurseFinanciare(string numeVechi, string numeNou, string data, double valuare, double nrExemplare, double durataViata)
throw(ValidationException, RepoException)
{
	Resurse* pVechi = new Resurse(numeVechi, 0, 0);
	ResurseFinanciare* pNou = new ResurseFinanciare(numeNou, data, valuare, nrExemplare,durataViata);
	this->repo->updateResurse(pVechi, pNou);
}

void Controller::updateResurseMateriale(string numeVechi, string numeNou, string data, double valuare, double moneda)
throw(ValidationException, RepoException)
{
	Resurse* pVechi = new Resurse(numeVechi, 0, 0);
	ResurseMateriale* pNou = new ResurseMateriale(numeNou, data, valuare, moneda);
	this->repo->updateResurse(pVechi, pNou);
}

void Controller::deleteResurse(string nume) throw(RepoException)
{
	Resurse* p = new Resurse(nume, 0, 0);
	this->repo->deleteResurse(p);
}

vector<Resurse*> Controller::filterByNume(string numeN, string dataN)
{
	vector<Resurse*> resurse = this->repo->getAll();
	vector<Resurse*> result;
	for (Resurse* p : resurse)
	{
		if (p->getNume() ==numeN  && p->getData() ==dataN )
		{
			result.push_back(p->clone());
		}
	}
	return result;
}

bool compareByValuare(Resurse* p1, Resurse* p2)
{
	return p1->getValuare() < p2->getValuare();
}

vector<Resurse*> Controller::sortByValuare()
{
	vector<Resurse*> resurse = this->repo->getAll();
	sort(resurse.begin(), resurse.end(), compareByValuare);
	return resurse;
}

int Controller::cumpara(string nume,  double valuare, double& pretTotal)
{
	pretTotal = 0;
	vector<Resurse*> resurse = this->repo->getAll();
	for (Resurse* p : resurse)
	{
		if (p->getNume() == nume)
			if (p->getValuare() >= valuare)
			{
				pretTotal = p->getValuare() * valuare;
				p->setValuare(p->getValuare() - valuare);
				this->saveToFile();
				return 0;
			}
			else
			{
				return -1;
			}
	}
	return -2;
}

int Controller::returneaza(string nume, int valuare)
{
	vector<Resurse*> resurse = this->repo->getAll();
	for (Resurse* p : resurse)
	{
		if (p->getNume() == nume)
		{
			p->setValuare(p->getValuare() + valuare);
			this->saveToFile();
			return 0;
		}
	}
	return -1;
}

void Controller::loadFromFile() throw(ReadFromFileException)
{
	this->repo->loadFromFile();
}

void Controller::saveToFile()
{
	this->repo->saveToFile();
}

void Controller::setFileName(string fileName)
{
	this->repo->setFileName(fileName);
}

void Controller::setRepo(RepoFile* repo)
{
	this->repo = repo;
}
