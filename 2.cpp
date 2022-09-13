#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef struct{
        double x;
        double y;
} Point;

typedef struct{
        char name[7];
        Point points[3];
} Person;

int main(void){
        Person students[3];
        for(int i = 0; i < 3; i++){
                cin >> students[i].name >> students[i].points[0].x >> students[i].points[0].y >> students[i].points[1].x >> students[i].points[1].y >> students[i].points[2].x >> students[i].points[2].y;
        }
        for(int j = 0; j < 3; j++){
                int len;
                int list[3];
                for(int k = 0; k < 3; k++){
                        len = sqrt(pow(abs(students[j].points[k].x), 2) + pow(abs(students[j].points[k].y), 2));
                        list[k] = len;
                }
		int max = 0;
		for(int a = 0; a < 3; a++){
			if(list[max] < list[a]){
				max = a;
			}
		cout << students[i].name << " (" << students[i].points[0].x << " " << students[i].points[0].y << ") (" << students[i].points[1].x << " " << students[i].points[1].y << ") (" << students[i].points[2].x << " " << students[i].points[2].y << ")" << endl;
		
		}
	}
}
