#pragma once
class TestController {
private:
    void testGetAll();
    void testGetResurseAtPosition();
    void testAddResurseFinanciare();
    void testAddResurseMateriale();
    void testDeleteResurse();
    void testUpdateResurseFinanciare();
    void testUpdateResurseMaterialet();
    void testFilterByValuare();
    void testSortByValuare();
    void testCumpara();
    void testReturneaza();
public:
    TestController();
    ~TestController();
    void testAll();
};