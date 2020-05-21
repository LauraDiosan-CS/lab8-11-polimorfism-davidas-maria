#include "ResurseFinanciare.h"
#include "Util.h"

ResurseFinanciare::ResurseFinanciare() : Resurse()
{
}

ResurseFinanciare::ResurseFinanciare(string nume, string data, double valuare, double nrExempl, double durataViata) : Resurse(nume,data, valuare)
{
	this->nrExempl = nrExempl;
	this->durataViata = durataViata;
}

ResurseFinanciare::ResurseFinanciare(const ResurseFinanciare& p) : Resurse(p)
{
	this->nrExempl = p.nrExempl;
	this->durataViata = p.durataViata;
}

ResurseFinanciare::~ResurseFinanciare()
{
}

Resurse* ResurseFinanciare::clone()
{
	return new ResurseFinanciare(this->nume,this->data, this->valuare, this->nrExempl,this->durataViata);
}

double ResurseFinanciare::getNrExempl()
{
	return this->nrExempl;
}

double ResurseFinanciare::getDurataViata()
{
	return this->durataViata;
}

void ResurseFinanciare::setNrExempl(double nrExempl)
{
	this->nrExempl = nrExempl;
}
void ResurseFinanciare::setDurataViata(double durataViata)
{
	this->durataViata = durataViata;
}

ResurseFinanciare& ResurseFinanciare::operator=(const ResurseFinanciare& p)
{
	Resurse::operator=(p);
	this->nrExempl = p.nrExempl;
	this->durataViata = p.durataViata;
	return *this;
}

bool ResurseFinanciare::operator==(const ResurseFinanciare& p)
{
	return Resurse::operator==(p) && this->nrExempl == p.nrExempl && this->durataViata==p.durataViata;
}

string ResurseFinanciare::toString(string delim)
{
	return "RF" + delim + Resurse::toString(delim) + delim + convertDoubleToString(this->nrExempl)+delim+ convertDoubleToString(this->durataViata);
}
