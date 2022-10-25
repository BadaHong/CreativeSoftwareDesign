#include <iostream>
#include "number.h"

using namespace std;

int main(){
        Number num;
        Square sqr;
        Cube cub;
        string input;
        while(1){
                cin >> input;
                if(input == "number"){
                        cin >> input;
                        num.setNumber(stoi(input));
                        cout << "getNumber(): " << num.Number::getNumber() << endl;
                }
                else if(input == "square"){
                        cin >> input;
                        num.setNumber(stoi(input));
                        sqr.setNumber(stoi(input));
                        cout << "getNumber(): " << num.Number::getNumber() << endl;
                        cout << "getSquare(): " << sqr.Square::getSquare() << endl;
                }
                else if(input == "cube"){
                        cin >> input;
                        num.setNumber(stoi(input));
                        sqr.setNumber(stoi(input));
                        cub.setNumber(stoi(input));
                        cout << "getNumber(): " << num.Number::getNumber() << endl;
                        cout << "getSquare(): " << sqr.Square::getSquare() << endl;
                        cout << "getCube(): " << cub.Cube::getCube() << endl;
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}

