#pragma once
#include "Resurse.h"
#include "ValidatorResurseFinanciare.h"
#include "ValidatorResurseMateriale.h"
#include <vector>

using namespace std;

class RepoFile {
protected:
	vector<Resurse*> resurse;
	string fileName;
	ValidatorResurseFinanciare validatorRF;
	ValidatorResurseMateriale validatorRM;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);

	RepoFile& operator=(const RepoFile& repo);

	vector<Resurse*> getAll();
	int getSize();
	Resurse* getResurse(int pos);
	int findResurse(Resurse* p);
	void addResurse(Resurse* p);
	void updateResurse(Resurse* pVechi, Resurse* pNou);
	void deleteResurse(Resurse* p);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


