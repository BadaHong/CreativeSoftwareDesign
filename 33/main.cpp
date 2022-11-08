#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;

int main(){
        vector<Shape*> arr;
        char input;
        while(1){
                cin >> input;
                if(input == 'r'){
                        double w, h;
                        cin >> w >> h;
                        arr.push_back(new Rectangle(w, h));
                }
                else if(input == 't'){
                        double w, h;
                        cin >> w >> h;
                        arr.push_back(new Triangle(w, h));
                }
                else if(input == '0'){
                        for(int i = 0; i < arr.size(); i++){
                                cout << arr[i]->getArea() << endl;
                        }
                        for(int i = 0; i < arr.size(); i++){
                                delete arr[i];
                        }
                        break;
                }
        }
        return 0;
}

