#pragma once
#include "Resurse.h"

class ResurseMateriale : public Resurse {
private:
	double moneda;
public:
	ResurseMateriale();
	ResurseMateriale(string nume, string data,double valuare, double moneda);
	ResurseMateriale(const ResurseMateriale& p);
	~ResurseMateriale();

	Resurse* clone();

	double getMoneda();
	void setMoneda(double moneda);
	ResurseMateriale& operator=(const ResurseMateriale& p);
	bool operator==(const ResurseMateriale& p);
	string toString(string delim);
};