#include "ResurseMateriale.h"
#include "Util.h"

ResurseMateriale::ResurseMateriale() : Resurse()
{
}

ResurseMateriale::ResurseMateriale(string nume,string data, double valuare, double moneda) : Resurse(nume, data,valuare)
{
	this->moneda = moneda;
}

ResurseMateriale::ResurseMateriale(const ResurseMateriale& p) : Resurse(p)
{
	this->moneda = p.moneda;
}

ResurseMateriale::~ResurseMateriale()
{
}

Resurse* ResurseMateriale::clone()
{
	return new ResurseMateriale(this->nume, this->data,this->valuare, this->moneda);
}

double ResurseMateriale::getMoneda()
{
	return this->moneda;
}

void ResurseMateriale::setMoneda(double moneda)
{
	this->moneda = moneda;
}

ResurseMateriale& ResurseMateriale::operator=(const ResurseMateriale& p)
{
	Resurse::operator=(p);
	this->moneda = p.moneda;
	return *this;
}

bool ResurseMateriale::operator==(const ResurseMateriale& p)
{
	return Resurse::operator==(p) && this->moneda == p.moneda;
}

string ResurseMateriale::toString(string delim)
{
	return "RM" + delim + Resurse::toString(delim) + delim + convertDoubleToString(this->moneda);
}
