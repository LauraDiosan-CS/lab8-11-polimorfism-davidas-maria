#include "RepoFileCSV.h"
#include <fstream>
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"

RepoFileCSV::RepoFileCSV() : RepoFile()
{
}

RepoFileCSV::RepoFileCSV(string fileName) : RepoFile(fileName)
{
}

RepoFileCSV::~RepoFileCSV()
{
}

void RepoFileCSV::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = ",";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "RF")
			{
				linie = linie.erase(0, 5);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

			    pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double valuare = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double nrExemplare = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double durataViata = stod(linie.substr(0, pos));
			

				ResurseFinanciare* rf= new ResurseFinanciare(nume, data, valuare, nrExemplare,durataViata);
				this->resurse.push_back(rf);
			}
			else if (linie.substr(0, 2) == "RM")
			{
				linie = linie.erase(0, 4);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

			    pos = linie.find(delim);
				string data = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double valuare = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double moneda = stod(linie.substr(0, pos));

				ResurseMateriale* rm = new ResurseMateriale(nume, data, valuare,moneda);
				this->resurse.push_back(rm);
			}
		}
		f.close();
	}
}

void RepoFileCSV::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Resurse* elem : this->resurse)
		{
			f << elem->toString(",") << endl;
		}
	}
}
