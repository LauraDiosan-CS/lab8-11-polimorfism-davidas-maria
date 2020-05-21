#include "RepoFile.h"
class Controller {
private:
	RepoFile* repo;
public:
	Controller();
	Controller(RepoFile* repo);
	~Controller();

	vector<Resurse*> getAll();
	Resurse* getResurseAtPosition(int pos);
	void addResurseFinanciare(string nume, string data, double valuare, double nrExemplare, double durataViata);
	void addResurseMateriale(string nume, string data, double valuare, double moneda);
    void updateResurseFinanciare(string numeVechi, string numeNou, string data, double valuare, double nrExemplare, double durataViata);
	void updateResurseMateriale(string numeVechi, string numeNou, string data, double valuare, double moneda);
	void deleteResurse(string nume);

	vector<Resurse*> filterByNume(string numeN, string dataN);
	vector<Resurse*> sortByValuare();
	int cumpara(string nume,  double valuare, double& pretTotal);
	int returneaza(string nume, int cantitate);

	void loadFromFile();
	void saveToFile();
	void setFileName(string fileName);
	void setRepo(RepoFile* repo);
};

bool compareByValuare(Resurse* p1, Resurse* p2);