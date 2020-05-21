#pragma once
#include <string>

using namespace std;
class Resurse {
protected:
	string nume,data;
	double valuare;

public:
	Resurse();
	Resurse(string nume,string data, double valuare);
	Resurse(const Resurse& p);
	~Resurse();

	virtual Resurse* clone();

	string getNume();
	string getData();
	double getValuare();
	void setNume(string nume);
	void setData(string data);
	void setValuare(double pret);
	Resurse& operator=(const Resurse& p);
	bool operator==(const Resurse& p);
	friend istream& operator>>(istream& is, Resurse& p);
	virtual string toString(string delim);
};