/* 
 * File:   main.cpp
 * Author: marcoyeung
 *
 * Created on February 9, 2014, 8:26 PM
 */

#include <cstdlib>
#include <iostream>

#include "TestType.h"

using namespace std;

class myC { 
    

public:
    myC():sp(0) {}
    /*myC(void) {  //can't be overloaded!
        sp=0;
    }*/
    void push(int value);
    
    int pop() {
        return stack[--sp];
    }
//protected:
    int data;
private:
    
    int stack[100];
    int sp; //=0; why can't initialze here?!
};


void myC::push(int value) {
    stack[sp++] = value;
    
}
class myCTwo: myC {
public:
    myCTwo(void):myC() {
        this->sum=0;
    }
    myCTwo(myCTwo const& src) { 
        sum = src.sum+1;
    }
    ~myCTwo() {
        cout<< "destroy me."<<endl;
    }
    void push(int value);
    int pop(void);
    int getSum(void);
private :
    int sum;
};

void myCTwo::push(int value) {
    myC::push(value);
    sum+=value;
}
int myCTwo::pop(void) {
    int d = myC::pop(); 
    sum-=d;
    return  d;
}
int myCTwo::getSum() {
    return sum;
}

void doClassTest() {
    cout <<" hello me" << endl;
    
    myCTwo me;
    me.push(1000);
    me.push(1010);
    me.push(1200);
    
    cout << me.pop() << endl;
    cout << "Sum is: " << me.getSum() << endl;
    cout << me.pop() << endl;
    cout << me.pop() << endl;
    cout << me.getSum() << endl;
    
    myCTwo me1 = me;
    
    myCTwo *me2;
    me2 = new myCTwo;
    myCTwo *me3 = new myCTwo();
    cout<< "get with pointer "<<(*me3).getSum() << endl;
    delete me3;
    
    int i;
    char tab[10];
    i = sizeof tab[0];
    
    cout<< "value of i: " << i << endl;
    
}
void doTestType() {
    TestType type;
    
    type.testTypeSize();
    
}
/*
 * 
 * 
 */
int main(int argc, char** argv) {
    doClassTest();
    return 0;
}
