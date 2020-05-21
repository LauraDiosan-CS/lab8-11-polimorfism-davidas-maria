#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
    const string fileNameInTXT = "TestResurseMateriale.txt";
    const string fileNameOutTXT = "TestResurseFinanciare.txt";
    const string fileNameInCSV = "TestResurseFinanciare.csv";
    const string fileNameOutCSV = "TestResurseMateriale.csv";

    //folosit pt. a testa lucrul cu fisiere
    vector<Resurse*> resurseIn;

    void testGetSize();
    void testGetAll();
    void testGetResurse();
    void testAddResurse();
   // void testUpdateResurse();
    void testDeleteResurse();


    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepoFile();
    ~TestRepoFile();
    void testAll();
};