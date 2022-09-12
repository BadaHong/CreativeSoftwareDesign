#include <stdio.h>
  
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
                scanf("%s %f %f %f %f %f %f", students[i].name, &students[i].points[0].x, &students[i].points[0].y, &students[i].points[1].x, &students[i].points[1].y, &students[i].points[2].x, &students[i].points[2].y);
        }
        for(int j = 0; j < 3; j++){
                printf("%s (%f %f) (%f %f) (%f %f)\n", students[j].name, students[j].points[0].x, students[j].points[0].y, students[j].points[1].x, students[j].points[1].y, students[j].points[2].x, students[j].points[2].y);
        }
}
