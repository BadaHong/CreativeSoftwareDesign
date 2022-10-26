#include <iostream>
#include "drop.h"
#include <string>

using namespace std;

int main(){
        Earth earth;
        Moon moon;
        string input;
        while(1){
                cin >> input;
                if(input == "Earth"){
                        float h;
                        cin >> h;
                        earth.Earth::simulate(h);
                }
                else if(input == "Moon"){
                        float h;
                        cin >> h;
                        moon.Moon::simulate(h);
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}

