/* 
 * File:   TestType.cpp
 * Author: iampolo
 * 
 * Created on May 31, 2014, 11:47 AM
 */

#include "TestType.h"
#include <iostream>
using namespace std;
    
TestType::TestType() {
}

TestType::TestType(const TestType& orig) {
}

TestType::~TestType() {
}

void TestType::testStruct() {
    Person john;
    john.hisHarStyle = HairColor::Blond;
    
    strcpy(john.fName, "kkk");
}
void TestType::testTypeSize() {

    cout << "This computing environments uses:" << endl;
    cout << sizeof (char) << " byte for chars" << endl;
    cout << sizeof (short int) << " bytes for shorts" << endl;
    cout << sizeof (int) << " bytes for ints" << endl;
    cout << sizeof (long int) << " bytes for longs" << endl;
    cout << sizeof (float) << " bytes for floats" << endl;
    cout << sizeof (double) << " bytes for doubles" << endl;
    cout << sizeof (bool) << " byte for bools" << endl;
    cout << sizeof (int *) << " bytes for pointers" << endl;
    cout << "enum value: " << HairColor:: Brown<< endl;
    printTest();
    return;
}

void printTest() {

    char HairColorStrings[][7] = {
        {"Black"},
        {"Red"},
        {"Auburn"},
        {"Brown"},
        {"Blond"},
        {"Silver"},
        {"Grey"}};

    cout << " not part of class: " << endl;
}


