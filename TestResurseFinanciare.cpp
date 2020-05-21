#include "TestResurseFinanciare.h"
#include <assert.h>
#include "ResurseFinanciare.h"
#include "Util.h"
#include <iostream>

void TestResurseFinanciare::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNrExempl();
	this->testSetNrExempl();
	this->testGetDurataViata();
	this->testSetDurataViata();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
	cout << "Testele pt ResFin au trecut!" << endl;
}

void TestResurseFinanciare::testImplicitConstructor()
{
	ResurseFinanciare p;
	assert(p.getNume().empty());
	assert(p.getData().empty());
	assert(p.getValuare() == 0);
}

void TestResurseFinanciare::testConstructorWithParameters()
{
	ResurseFinanciare p("donatii","12.mar.2020", 300, 5, 7);
	assert(p.getNume() == "donatii");
	assert(p.getData() == "12.mar.2020");
	assert(p.getValuare() == 300);
}

void TestResurseFinanciare::testCopyConstructor()
{
	ResurseFinanciare p1("donatii", "12.mar.2020", 300, 5, 7);
	ResurseFinanciare p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurseFinanciare::testClone()
{
	ResurseFinanciare p("donatii", "12.mar.2020", 300, 5, 7);
	ResurseFinanciare* pClone = (ResurseFinanciare*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestResurseFinanciare::testGetNrExempl()
{
	ResurseFinanciare p("donatii", "12.mar.2020", 300, 5, 7);
	assert(p.getNume() == "donatii");
}

void TestResurseFinanciare::testSetNrExempl()
{
	ResurseFinanciare p;
	p.setNume("donatii");
	assert(p.getNume() == "donatii");
}
void TestResurseFinanciare::testGetDurataViata()
{
	ResurseFinanciare p("donatii", "12.mar.2020", 300, 5, 7);
	assert(p.getNume() == "donatii");
}

void TestResurseFinanciare::testSetDurataViata()
{
	ResurseFinanciare p;
	p.setNume("donatii");
	assert(p.getNume() == "donatii");
}

void TestResurseFinanciare::testAssignmentOperator()
{
	ResurseFinanciare p1("donatii", "12.mar.2020", 300, 5, 7);
	ResurseFinanciare p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurseFinanciare::testEqualityOperator()
{
	ResurseFinanciare p1("donatii", "12.mar.2020", 300, 5, 7);
	ResurseFinanciare p2 = p1;
	assert(p1 == p2);
	p2.setNume("proiecte");
	assert(!(p1 == p2));
	p2.setNume(p1.getNume());
	assert(p1 == p2);
	p2.setData("8.ianuarie.2020");
	assert(!(p1 == p2));
	p2.setData(p1.getData());
	assert(p1 == p2);
	p2.setValuare(1000);
	assert(!(p1 == p2));
	p2.setValuare(p1.getValuare());
	assert(p1 == p2);
}

void TestResurseFinanciare::testToString()
{
	ResurseFinanciare p("donatii", "12mar2020", 300, 5, 7);
	assert(p.toString(" ") == "RF donatii 12mar2020 300 5 7");
	assert(p.toString(",") == "RF,donatii,12mar2020,300,5,7");
}
