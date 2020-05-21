#include <assert.h>
#include "TestRepoFile.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include<iostream>


void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTXT();
	assert(repoFile->getSize() == 0);
	repoFile->addResurse(new Resurse());
	assert(repoFile->getSize() == 1);
}

void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	ResurseMateriale* p2 = new ResurseMateriale("proiecte", "6.ian.2020", 1000, 10);
	repoFile->addResurse(p1);
	repoFile->addResurse(p2);
	vector<Resurse*> produse = repoFile->getAll();
	assert(*produse[0] == *p1->clone());
	assert(*produse[1] == *p2->clone());
}

void TestRepoFile::testGetResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(p);
	assert(*repoFile->getResurse(0) == *p->clone());
	assert(*repoFile->getResurse(-1) == *(new Resurse()));
	assert(*repoFile->getResurse(1) == *(new Resurse()));
}

void TestRepoFile::testAddResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(p);
	assert(*repoFile->getResurse(0) == *p->clone());
}

/*void TestRepoFile::testUpdateResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(p1);
	ResurseFinanciare* p2 = new ResurseFinanciare("proiecte", "5.ian.2020", 1000, 10, 5);
	ResurseFinanciare* p3 = new ResurseFinanciare("chelt",  "22.apr.2020",500, 5, 15);
	repoFile->updateResurse(p3, p2);
	assert(*repoFile->getResurse(0) == *p1);
	repoFile->updateResurse(p1, p2);
	assert(*repoFile->getResurse(0) == *p2);
}
*/
void TestRepoFile::testDeleteResurse()
{
	RepoFile* repoFile = new RepoFileTXT();
	ResurseFinanciare* p1 = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(p1);
	ResurseFinanciare* p2 = new ResurseFinanciare("proiecte", "5.ian.2020", 1000, 10, 5);
	repoFile->deleteResurse(p2);
	assert(repoFile->getSize() == 1);
	assert(*repoFile->getResurse(0) == *p1);
	repoFile->deleteResurse(p1);
	assert(repoFile->getSize() == 0);
}






void TestRepoFile::testSavetoFileTXT()
{
	RepoFile* repoFile = new RepoFileTXT(this->fileNameOutTXT);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTXT);
	ResurseFinanciare* newProdus = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(newProdus);
	repoFile->saveToFile();
	repoFile->loadFromFile();

}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repoFile = new RepoFileCSV(this->fileNameInCSV);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameInCSV);
	ResurseFinanciare* newProdus = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	repoFile->addResurse(newProdus);
	repoFile->saveToFile();
	repoFile->loadFromFile();

}

TestRepoFile::TestRepoFile()
{
	ResurseFinanciare* p1 = new ResurseFinanciare("donatii", "12.mar.2020", 300, 5, 7);
	ResurseMateriale* p2 = new ResurseMateriale("proiecte", "6.ian.2020", 1000, 10);
	this->resurseIn.push_back(p1);
	this->resurseIn.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetResurse();
	this->testAddResurse();
	//this->testUpdateResurse();
	this->testDeleteResurse();

	this->testSavetoFileTXT();
	this->testSaveToFileCSV();
	cout << "Testele pt clasele de Repo au trecut!" << endl;
}
