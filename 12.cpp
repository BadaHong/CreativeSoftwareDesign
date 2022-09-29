//this program uses command argument to concatenate strings and add all the integers
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char** argv){
        string conc = "";
        int sum = 0;
        for(int i = 1; i < argc; i++){
                int num = atoi(argv[i]);
                if(num == 0){
                        conc += argv[i];
                }
                else{
                        sum += atoi(argv[i]);
                }
        }
        cout << conc << endl;
        cout << sum << endl;
        return 0;
}
