#include "TestResurseMateriale.h"
#include <assert.h>
#include "ResurseMateriale.h"
#include "Util.h"
#include<iostream>

void TestResurseMateriale::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetMoneda();
	this->testSetMoneda();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
	cout << "Testele pt ResMat au trecut!" << endl;
}

void TestResurseMateriale::testImplicitConstructor()
{
	ResurseMateriale p;
	assert(p.getNume().empty());
	assert(p.getData().empty());
	assert(p.getValuare() == 0);
}

void TestResurseMateriale::testConstructorWithParameters()
{
	ResurseMateriale p("donatii", "12.mar.2020", 300, 5);
	assert(p.getNume() == "donatii");
	assert(p.getData() == "12.mar.2020");
	assert(p.getValuare() == 300);
}

void TestResurseMateriale::testCopyConstructor()
{
	ResurseMateriale p1("donatii", "12.mar.2020", 300, 5);
	ResurseMateriale p2(p1);
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurseMateriale::testClone()
{
	ResurseMateriale p("donatii", "12.mar.2020", 300, 5);
	ResurseMateriale* pClone = (ResurseMateriale*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestResurseMateriale::testGetMoneda()
{
	ResurseMateriale p("donatii", "12.mar.2020", 300, 5);
	assert(p.getNume() == "donatii");
}

void TestResurseMateriale::testSetMoneda()
{
	ResurseMateriale p;
	p.setNume("donatii");
	assert(p.getNume() == "donatii");
}

void TestResurseMateriale::testAssignmentOperator()
{
	ResurseMateriale p1("donatii", "12.mar.2020", 300, 5);
	ResurseMateriale p2;
	p2 = p1;
	assert(p2.getNume() == p1.getNume());
	assert(p2.getData() == p1.getData());
	assert(p2.getValuare() == p1.getValuare());
}

void TestResurseMateriale::testEqualityOperator()
{
	ResurseMateriale p1("donatii", "12.mar.2020", 300, 5);
	ResurseMateriale p2 = p1;
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

void TestResurseMateriale::testToString()
{
	ResurseMateriale p("donatii", "12mar2020", 300, 5);
	assert(p.toString(" ") == "RM donatii 12mar2020 300 5");
	assert(p.toString(",") == "RM,donatii,12mar2020,300,5");
}
