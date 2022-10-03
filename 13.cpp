//this program will examine the minimum and maximum numbers from a list of numbers from command-line argument. it will include how to create dynamically allocated memory and use function by passing values as reference to parameter.

#include <iostream>
#include "minmax.h"

using namespace std;

#include <iostream>
#include <cstdlib>

void getMinMax(int* arr, int len, int& min, int& max){
        for(int i = 0; i < len; i++){
                if(min > arr[i]){
                        min = arr[i];
                }
                if(max < arr[i]){
                        max = arr[i];
                }
        }
}

int main(int argc, const char** argv){
        int len = argc - 1;
        int *arr = new int[len];
        for(int i = 1; i < argc; i++){
                arr[i-1] = atoi(argv[i]);
        }
        int min = arr[0];
        int max = arr[0];
        getMinMax(arr, len, min, max);
        cout << "min: " << min << endl;
        cout << "max: " << max << endl;
        delete[] arr;
        return 0;
}
