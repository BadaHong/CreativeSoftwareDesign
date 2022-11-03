#include <iostream>
#include <vector>
#include "animal.h"

using namespace std;

int main(){
        vector<Animal*> animals;
        string input;
        while(1){
                cin >> input;
                if(input == "z"){
                        string name;
                        int age;
                        int num;
                        cin >> name >> age >> num;
                        animals.push_back(new Zebra(name, age, num));
                }
                else if(input == "c"){
                        string name;
                        int age;
                        string toy;
                        cin >> name >> age >> toy;
                        animals.push_back(new Cat(name, age, toy));
                }
                else if(input == "0"){
                        for(int i = 0; i < animals.size(); i++){
                                animals[i]->printInfo();
                        }
                        for(int i = 0; i < animals.size(); i++){
                                delete animals[i];
                        }
                        animals.clear();
                        break;
                }
        }
        return 0;
}

