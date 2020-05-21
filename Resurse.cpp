#include "Resurse.h"
#include "Util.h"

Resurse::Resurse()
{
	this->valuare = 0;
}

Resurse::Resurse(string nume,string data ,double valuare)
{

	this->nume = nume;

	this->data = data;
	this->valuare = valuare;
}

Resurse::Resurse(const Resurse& p)
{
	this->nume = p.nume;
	this->data = p.data;
	this->valuare = p.valuare;
}

Resurse::~Resurse()
{
}

Resurse* Resurse::clone()
{
	return new Resurse(this->nume,this->data, this->valuare);
}

string Resurse::getNume()
{
	return this->nume;
}
string Resurse::getData()
{
	return this->data;
}
double Resurse::getValuare()
{
	return this->valuare;
}

void Resurse::setNume(string nume)
{
	this->nume = nume;
}
void Resurse::setData(string data)
{
	this->data = data;
}

void Resurse::setValuare(double valuare)
{
	this->valuare = valuare;
}

Resurse& Resurse::operator=(const Resurse& p)
{
	this->nume = p.nume;
	this->data = p.data;
	this->valuare = p.valuare;
	return *this;
}

bool Resurse::operator==(const Resurse& p)
{
	return this->nume == p.nume && this->data== p.data && this->valuare == p.valuare;
}

string Resurse::toString(string delim)
{
	return this->nume + delim+this->data+delim + convertDoubleToString(this->valuare);
}
