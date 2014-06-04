/* 
 * File:   Pet.h
 * Author: iampolo
 *
 * Created on June 2, 2014, 10:36 PM
 */

#ifndef PET_H
#define	PET_H
#include <iostream>
#include <string>
using namespace std;
class Pet {
protected:
    string Name;
public:
    Pet() {}
    Pet(string n) { Name = n;
        MakeSound();  //pay attention to this;before subclass are created. Pet's is used.
    }
    void Run(void) { cout << Name << " Pet says: I'm running" << endl; }
    virtual void MakeSound(void) {cout << Name << " The pet Says multi-languages." <<endl;}
    int doTest(void);
    void doTest2(void);
    void doTestPtr(void);
    void doTestPass(void);
    void doTestPassByVal(void);
    void doTestRefNoVirtual(void);
    void doTestPtrWithVirtual(void);
    
    void WakeUp(void) { MakeSound();}
    void NameMe(string name) { this -> Name = name; }
    
private:
};

class Cat : public Pet {
public:
    Cat(string n) : Pet(n) {};
    void MakeSound(void) { cout << Name << " Cat says: Meow! Meow!" << endl; }
};

class Dog : public Pet {
public:
    Dog(string n) : Pet(n) {};
    void MakeSound(void) { cout << Name << " Dog says: Woof! Woof!" << endl; }
};

class GermanShepherd: public Dog { 
public: 
    GermanShepherd(string name): Dog(name) {}
    void MakeSound() {cout << Name << " says: Wuff !" << endl; }
    void Laufen(void) {cout << Name << " runs (gs)!" << endl;}
};
class MastinEspanol : public Dog {
public: 
    MastinEspanol(string name) : Dog(name) {}
    void MakeSound(void) { cout << Name << " says: Guau!" << endl; }
    void Ejecutar(void) { cout << Name << " runs (mes)!" << endl; }
};

void PlayWithPet(Pet &pet) {
    pet.MakeSound();
    //could be dangerous;
    try {
        dynamic_cast<GermanShepherd &>(pet).Laufen();
        dynamic_cast<MastinEspanol &>(pet).Ejecutar();    
    } catch(...) {}
}

//test without virtual keyword
//can also change to test with virtual keyword and check the diff.
void Pet::doTestRefNoVirtual(void) {
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd gs("Hund");
    MastinEspanol mes("Perro");
    cout << "Test Start:" << endl;
    PlayWithPet(pet); //call with reference
    PlayWithPet(dog);
    PlayWithPet(gs);
    PlayWithPet(mes);
}

void PlayWithPet(Pet *pet) {
    GermanShepherd *gs;
    MastinEspanol *mes;

    //must have 'virtual' function to succeed ?!!
//    pet->MakeSound();
    if(gs = dynamic_cast<GermanShepherd *>(pet))
            gs -> Laufen();
    if(mes = dynamic_cast<MastinEspanol *>(pet))
            mes -> Ejecutar();    
}
void Pet::doTestPtrWithVirtual(void) {
    Pet *pet = new Pet("creature");
    Dog *dog = new Dog("Dog");
    GermanShepherd *gs = new GermanShepherd("Hund");
    MastinEspanol *mes = new MastinEspanol("Perro");
    cout << "Test Start:" << endl;
    PlayWithPet(pet); //not German shepherd /mastinespanol or subclass of them
    PlayWithPet(dog);//not German shepherd /mastinespanol or subclass of them
    PlayWithPet(gs); //valid object to cast
    PlayWithPet(mes);      //valid object to cast
}


//pass object to function
void PlayWithPetByPointer(string name, Pet *pet) {
	pet -> NameMe(name);
	pet -> MakeSound();
}
void PlayWithPetByReference(string name, Pet &pet) {
	pet.NameMe(name);
	pet.MakeSound();
}

void PlayPetByValue(string name, Pet pet) {
    pet.NameMe(name);//change can't be seen outside this method
    pet.MakeSound();
}


//object can be passed by value like primitive type
void Pet::doTestPassByVal(void) {
    Pet pet;
    pet.NameMe("no_name");
    PlayPetByValue("Alpha", pet); //
    pet.MakeSound();
    
    PlayWithPetByPointer("Beta", &pet);
    pet.MakeSound();
    PlayWithPetByReference("Gamma", pet);
    pet.MakeSound();    
}

void Pet::doTestPass(void) {
    Pet *p1 = new Pet;
    Pet p2; //automatic variable
    PlayWithPetByPointer("anonymous", p1);
    PlayWithPetByReference("no_name", p2); //pass with reference
    PlayWithPetByPointer("no_name", &p2); //get the address with &
    PlayWithPetByReference("anonymous", *p1); //get the actual object with *
}

void Pet::doTestPtr(void) {
    Pet *a_pet1, *a_pet2;
    Cat *a_cat;
    Dog *a_dog;

    a_pet1 = a_cat = new Cat("Kitty w/ pointer ");
    a_pet2 = a_dog = new Dog("Doggie w/ pointer ");
    a_pet1 -> MakeSound(); //calling Pet's, since there is not 'virtual'
    a_cat -> MakeSound();
    a_pet2 -> MakeSound();
    a_dog -> MakeSound();
    a_dog -> WakeUp();
    return;
}
void Pet::doTest2(void) {
    Cat *a_cat;
    Dog *a_dog;
    a_cat = new Cat("Kitty ");
    a_dog = new Dog("Doggie ");
    
    a_cat -> MakeSound();
    static_cast<Pet *> (a_cat) -> MakeSound(); //calling Pet's, since there is not 'virtual'
    a_dog -> MakeSound();
    static_cast<Pet *> (a_dog) -> MakeSound();
    return;
}

int Pet::doTest(void) {
	Pet a_pet("pet");
	Cat a_cat("Tom");
	Dog a_dog("Spike");
	a_pet.Run();
	a_dog.Run(); a_dog.MakeSound();
	a_cat.Run(); a_cat.MakeSound();
        
        
        Pet *apPtr = new Cat("KTom");
        static_cast<Dog *>(apPtr)->MakeSound();
        static_cast<Cat *>(apPtr)->MakeSound(); /** abuse */
//        dynamic_cast<Cat *>(apPtr)->MakeSound(); //error
        
	return 0;
}

#endif	/* PET_H */

