#include <iostream>
#include <string>

using namespace std;

typedef struct{
        string name;
        double score;
} Person;

int main(int argc, const char** argv){
        int N = (argc-1)/2;
        Person *arr = new Person[N];
        int count = 1;
        for(int i = 0; i < N; i++){
                arr[i].name = argv[count];
                count++;
                arr[i].score = atof(argv[count]);
                count++;
        }
        for(int j = 0; j < N; j++){
                cout << "Name: " << arr[j].name << ", Score: " << arr[j].score << endl;
        }
        delete[] arr;
        return 0;
}

