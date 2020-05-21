#include "TestResurse.h"
#include <assert.h>
#include "Resurse.h"
#include "Util.h"
#include <iostream>

void TestResurse::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetNume();
	this->testSetNume();
	//this->testGetDurata();
	//this->testSetDurata();
	this->testGetValuare();
	this->testSetValuare();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
	cout << "Testele pt Resurse au trecut!" << endl;

}

void TestResurse::testImplicitConstructor()
{
	Resurse p;
	assert(p.getNume().empty());
	assert(p.getData().empty());
	assert(p.getValuare() == 0);
}

void TestResurse::testConstructorWithParameters()
{
	Resurse p("donatii","12.mar.2020", 300);
	assert(p.getNume() == "donatii");
	assert(p.getData() == "12.mar.2020");
	assert(p.getValuare() == 300);
}

void TestResurse::testCopyConstructor()
{
	Resurse p1("donatii", "12.mar.2020", 300);
	Resurse p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurse::testClone()
{
	Resurse p("donatii", "12.mar.2020", 300);
	Resurse* pClone = p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestResurse::testGetNume()
{
	Resurse p("donatii", "12.mar.2020", 300);
	assert(p.getNume() == "donatii");
}

void TestResurse::testSetNume()
{
	Resurse p;
	p.setNume("donatii");
	assert(p.getNume() == "donatii");
}

void TestResurse::testGetData()
{
	Resurse p("donatii", "12.mar.2020", 300);
	assert(p.getData() == "12.mar.2020");
}

void TestResurse::testSetData()
{
	Resurse p;
	p.setData("12.mar.2020");
	assert(p.getData() == "12.mar.2020");
}
void TestResurse::testGetValuare()
{
	Resurse p("donatii", "12.mar.2020", 300);
	assert(p.getValuare() == 300);
}

void TestResurse::testSetValuare()
{
	Resurse p;
	p.setValuare(300);
	assert(p.getValuare() == 300);
}

void TestResurse::testAssignmentOperator()
{
	Resurse p1("donatii", "12.mar.2020", 300);
	Resurse p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurse::testEqualityOperator()
{
	Resurse p1("donatii", "12.mar.2020", 300);
	Resurse	p2 = p1;
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

void TestResurse::testToString()
{
	Resurse p("donatii", "12.mar.2020", 300);
	assert(p.toString(" ") == "donatii 12.mar.2020 300");
	assert(p.toString(",") == "donatii,12.mar.2020,300");
}
