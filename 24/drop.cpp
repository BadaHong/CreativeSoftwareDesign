#include <iostream>
#include <cmath>
#include "drop.h"

using namespace std;

Planet::Planet(float gravity){
        gravity_ = gravity;
}

float Planet::drop(float height){
        time = sqrt((2*height)/gravity_);
        return time;
}

Earth::Earth(): Planet(9.81){
}

void Earth::simulate(float height){
        cout << "Earth gravity = " << gravity_ << endl;
        cout << "Drop from " << height << "m, " << Planet::drop(height) << " seconds." << endl;
}

Moon::Moon(): Planet(1.62){
}

void Moon::simulate(float height){
        cout << "Moon gravity = " << gravity_ << endl;
        cout << "Drop from " << height << "m, " << Planet::drop(height) << " seconds." << endl;
}                                                                                                    
