#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal(string name_, int age_){
        name = name_;
        age = age_;
}

void Animal::printInfo(){}

Zebra::Zebra(string name_, int age_, int numS): Animal::Animal(name_, age_), numStripes(numS){}

void Zebra::printInfo(){
        cout << "Zebra, Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << endl;
}

Cat::Cat(string name_, int age_, string favToy): Animal::Animal(name_, age_), favoriteToy(favToy){}

void Cat::printInfo(){
        cout << "Cat, Name: " << name << ", Age: " << age << ", Favorite toy: " << favoriteToy << endl;
}
~  
