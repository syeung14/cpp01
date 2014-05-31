/* 
 * File:   TestType.h
 * Author: iampolo
 *
 * Created on May 31, 2014, 11:47 AM
 */

#ifndef TESTTYPE_H
#define	TESTTYPE_H

class TestType {
public:
    TestType();
    TestType(const TestType& orig);
    virtual ~TestType();
    
    void testTypeSize(void);
    void testStruct(void);
private:

};

namespace HairColor {
    enum HairColor {Black, Blond, Red,Brown };
}
//C way of struct
struct Person {
    char fName[25];
    char lName[25];
    HairColor::HairColor hisHarStyle;
    
};
void printTest(void);

//C++ way of struct
//elements are by default public
struct AsianPerson {
public:
protected:
    int size;    
private:
    char fName[25];
    char lName[25];
    HairColor::HairColor hisHarStyle;
};





#endif	/* TESTTYPE_H */

