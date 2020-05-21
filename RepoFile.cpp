#include "RepoFile.h"
#include <typeinfo>
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include "ValidationException.h"
#include "RepoException.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}

RepoFile::~RepoFile()
{
	this->emptyRepo();
}

void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}

RepoFile& RepoFile::operator=(const RepoFile& repo)
{
	this->fileName = repo.fileName;
	return *this;
}

vector<Resurse*> RepoFile::getAll()
{
	return this->resurse;
}

int RepoFile::getSize()
{
	return this->resurse.size();
}

Resurse* RepoFile::getResurse(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->resurse[pos]->clone();
	}
	return new Resurse();
}

int RepoFile::findResurse(Resurse* p)
{
	for (int i = 0; i < this->resurse.size(); i++)
	{
		if (this->resurse[i]->getNume() == p->getNume())
		{
			return i;
		}
	}
	return -1;
}

void RepoFile::addResurse(Resurse* p) throw(ValidationException, RepoException)
{
	if (typeid(*p) == typeid(ResurseFinanciare))
	{
		this->validatorRF.validate(p);
	}
	if (typeid(*p) == typeid(ResurseMateriale))
	{
		this->validatorRM.validate(p);
	}
	if (this->findResurse(p) >= 0)
	{
		throw RepoException("Exista deja o resursea cu numele dat!");
	}
	this->resurse.push_back(p->clone());
	this->saveToFile();
}


void RepoFile::updateResurse(Resurse* pVechi, Resurse* pNou) throw(ValidationException, RepoException)
{

	if (typeid(*pNou) == typeid(ResurseFinanciare))
	{
		this->validatorRF.validate(pNou);
	}
	if (typeid(*pNou) == typeid(ResurseMateriale))
	{
		this->validatorRM.validate(pNou);
	}
	if (this->findResurse(pVechi) < 0)
	{
		throw RepoException("Nu exista nici o resursa cu numele dat!");
	}
	for (int i = 0; i < this->resurse.size(); i++)
	{
		if (this->getResurse(i)->getNume() == pVechi->getNume())
		{
			delete this->resurse[i];
			this->resurse[i] = pNou->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepoFile::deleteResurse(Resurse* p) throw(RepoException)
{
	for (int i = 0; i < this->resurse.size(); i++)
	{
		// this->produse.begin() + i <=> un iterator care pointeaza spre pozitia i din vector
		if (this->resurse[i]->getNume() == p->getNume())
		{
			delete this->resurse[i];
			//este necesar un iterator pt. metoda erase
			this->resurse.erase(this->resurse.begin() + i);
			this->saveToFile();
			return;
		}
    }
	throw RepoException("Nu exista nici o resursa cu numele dat!");
}

void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->resurse[i];
	}
	this->resurse.clear();
}

