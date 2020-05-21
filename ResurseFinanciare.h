#pragma once
#include "Resurse.h"

class ResurseFinanciare : public Resurse {
private:
	double nrExempl;
	double durataViata;
public:
	ResurseFinanciare();
	ResurseFinanciare(string nume, string data, double valuare, double nrExemplare, double durataViata);
	ResurseFinanciare(const ResurseFinanciare& p);
	~ResurseFinanciare();

	Resurse* clone();

	double getNrExempl();
	double getDurataViata();
	void setNrExempl(double nrExempl);
	void setDurataViata(double durataViata);
	ResurseFinanciare& operator=(const ResurseFinanciare& p);
	bool operator==(const ResurseFinanciare& p);
	string toString(string delim);
};