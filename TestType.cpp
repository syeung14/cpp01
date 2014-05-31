/* 
 * File:   TestType.cpp
 * Author: iampolo
 * 
 * Created on May 31, 2014, 11:47 AM
 */

#include "TestType.h"
#include <iostream>

TestType::TestType() {
}

TestType::TestType(const TestType& orig) {
}

TestType::~TestType() {
}

enum HairColor {Black, Blond, Red,Brown };

void TestType::testTypeSize() {
    using namespace std;
    cout << "This computing enviroments uses:" << endl;
    cout << sizeof (char) << " byte for chars" << endl;
    cout << sizeof (short int) << " bytes for shorts" << endl;
    cout << sizeof (int) << " bytes for ints" << endl;
    cout << sizeof (long int) << " bytes for longs" << endl;
    cout << sizeof (float) << " bytes for floats" << endl;
    cout << sizeof (double) << " bytes for doubles" << endl;
    cout << sizeof (bool) << " byte for bools" << endl;
    cout << sizeof (int *) << " bytes for pointers" << endl;
    return;
}


