#include "Controller.h"
#include "TestController.h"
#include <assert.h>
#include "RepoFileTXT.h"
#include "ResurseFinanciare.h"
#include "ResurseMateriale.h"
#include "RepoException.h"
#include <vector>

void TestController::testGetAll()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt","12.05.2018" ,30, 5, 5);
	ResurseMateriale* p2 = new ResurseMateriale("don", "12.sept.2019",500, 10);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(), p1->getDurataViata());
	ctrl.addResurseMateriale(p2->getNume(), p2->getData(), p2->getValuare(), p2->getMoneda());
	vector<Resurse*> resurse = ctrl.getAll();
	assert(*resurse[0] == *p1);
	assert(*resurse[1] == *p2);
}

void TestController::testGetResurseAtPosition()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	ctrl.addResurseFinanciare(p->getNume(), p->getData(), p->getValuare(), p->getNrExempl(), p->getDurataViata());
	try {
		assert(*ctrl.getResurseAtPosition(0) == *p);
	}
	catch (...) {
		assert(false);
	}
	try {
		*ctrl.getResurseAtPosition(-1);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	try {
		*ctrl.getResurseAtPosition(1);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
}

void TestController::testAddResurseFinanciare()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* pd1 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	try {
		ctrl.addResurseFinanciare(pd1->getNume(),  pd1->getData(), pd1->getValuare(), pd1->getNrExempl(), pd1->getDurataViata());
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *pd1);
	ResurseFinanciare* pd2 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 1);
	try {
		ctrl.addResurseFinanciare(pd2->getNume(), pd1->getData(), pd2->getValuare(), pd2->getNrExempl(), pd2->getDurataViata());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *pd1);
}

void TestController::testAddResurseMateriale()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseMateriale* ps1 = new ResurseMateriale("don", "12.sept.2019", 500, 10);
	try {
		ctrl.addResurseMateriale(ps1->getNume(), ps1->getData(), ps1->getValuare(), ps1->getMoneda());
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *ps1);
	ResurseMateriale* ps2 = new ResurseMateriale("don", "12.sept.2019", 50, 1);
	try {
		ctrl.addResurseMateriale(ps2->getNume(), ps2->getData(), ps2->getValuare(), ps2->getMoneda());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *ps1);
}

void TestController::testUpdateResurseFinanciare()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt","24.11.2019", 300, 5, 2);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(), p1->getDurataViata());
	ResurseFinanciare* p2 = new ResurseFinanciare("don", "1.4.2000",50, 10, 6);
	ResurseFinanciare* p3 = new ResurseFinanciare("asig", "8.12.2019",50, 12, 4);
	try {
		ctrl.updateResurseFinanciare(p3->getNume(), p2->getNume(), p2->getData(), p2->getValuare(), p2->getNrExempl(), p2->getDurataViata());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *p1);
	try {
		ctrl.updateResurseFinanciare(p1->getNume(), p2->getNume(), p2->getData(), p2->getValuare(), p2->getNrExempl(), p2->getDurataViata());
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *p2);
}

void TestController::testUpdateResurseMaterialet()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseMateriale* p1 = new ResurseMateriale("chit","3.1.2018", 30, 10);
	ctrl.addResurseMateriale(p1->getNume(), p1->getData(), p1->getValuare(), p1->getMoneda());
	ResurseMateriale* p2 = new ResurseMateriale("secr","21.01.2017", 200, 5);
	ResurseMateriale* p3 = new ResurseMateriale("festiv","30.11.2020", 50, 5);
	try {
		ctrl.updateResurseMateriale(p3->getNume(), p2->getNume(), p2->getData(), p2->getValuare(), p2->getMoneda());
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *p1);
	try {
		ctrl.updateResurseMateriale(p1->getNume(), p2->getNume(), p2->getData(), p2->getValuare(), p2->getMoneda());
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *p2);
}

void TestController::testDeleteResurse()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt","12.4.2020",50,5,1);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(),p1->getDurataViata());
	try {
		ctrl.deleteResurse("briosa");
		assert(false);
	}
	catch (RepoException & e) {
	}
	catch (...) {
		assert(false);
	}
	assert(*ctrl.getResurseAtPosition(0) == *p1);
	try {
		ctrl.deleteResurse(p1->getNume());
	}
	catch (...) {
		assert(false);
	}
}

void TestController::testFilterByValuare()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	ResurseMateriale* p2 = new ResurseMateriale("secr", "21.01.2017", 200, 5);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(),p1->getDurataViata());
	ctrl.addResurseMateriale(p2->getNume(), p2->getData(), p2->getValuare(), p2->getMoneda());

/*	vector<Resurse*> filterResult = ctrl.filterByValuare(0, 4);
	assert(filterResult.size() == 0);
	filterResult = ctrl.filterByValuare(30, 40);
	assert(filterResult.size() == 0);
	filterResult = ctrl.filterByValuare(4, 7);
	assert(filterResult.size() == 1);
	assert(*filterResult[0] == *p1);
	filterResult = ctrl.filterByValuare(10, 28);
	assert(filterResult.size() == 1);
	assert(*filterResult[0] == *p2);
	filterResult = ctrl.filterByValuare(2, 44);
	assert(filterResult.size() == 2);
	assert(*filterResult[0] == *p1);
	assert(*filterResult[1] == *p2);
*/}

void TestController::testSortByValuare()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	ResurseMateriale* p2 = new ResurseMateriale("secr", "21.01.2017", 200, 5);
	ResurseFinanciare* p3 = new ResurseFinanciare("imprum","12.5.2018", 5000, 30, 10);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(), p1->getDurataViata());
	ctrl.addResurseMateriale(p2->getNume(), p2->getData(), p2->getValuare(), p2->getMoneda());
	ctrl.addResurseFinanciare(p3->getNume(), p3->getData(), p3->getValuare(), p3->getNrExempl(), p3->getDurataViata());

	vector<Resurse*> filterResult = ctrl.sortByValuare();
	assert(filterResult.size() == 3);
	assert(*filterResult[0] == *p2);
	assert(*filterResult[1] == *p3);
	assert(*filterResult[2] == *p1);
}

void TestController::testCumpara()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	double pretTotal;
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(), p1->getDurataViata());

	//assert(ctrl.cumpara("imprum", 5000, pretTotal) == -2);
	//assert(ctrl.cumpara(p1->getNume(), 600, pretTotal) == -1);
	//assert(ctrl.cumpara(p1->getNume(), 50, pretTotal) == 0);
	//assert(pretTotal == 250);
	//assert(ctrl.getResurseAtPosition(0)->getValuare() == 450);
}

void TestController::testReturneaza()
{
	Controller ctrl;
	RepoFile* repoFile = new RepoFileTXT();
	ctrl.setRepo(repoFile);
	double pretTotal;
	ResurseFinanciare* p1 = new ResurseFinanciare("chelt", "12.05.2018", 30, 5, 5);
	ctrl.addResurseFinanciare(p1->getNume(), p1->getData(), p1->getValuare(), p1->getNrExempl(), p1->getDurataViata());

	assert(ctrl.returneaza("ciocolata", 2) == -1);
	assert(ctrl.returneaza(p1->getNume(), 50) == 0);
	assert(ctrl.getResurseAtPosition(0)->getValuare() == 550);
}

TestController::TestController()
{
}

TestController::~TestController()
{
}

void TestController::testAll()
{
	this->testGetAll();
	this->testGetResurseAtPosition();
	this->testAddResurseFinanciare();
	this->testAddResurseMateriale();
	this->testUpdateResurseFinanciare();
	this->testUpdateResurseMaterialet();
	this->testDeleteResurse();

	this->testFilterByValuare();
	this->testSortByValuare();
	this->testCumpara();
	this->testReturneaza();
}
