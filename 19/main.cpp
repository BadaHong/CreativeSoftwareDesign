#include <iostream>
#include <string>
#include <vector>
#include "sorted.h"

int main(){
        SortedArray number;
        vector<int> num;
        while(1){
                string input;
                cin >> input;
                if(input == "ascend"){
                        num = number.GetSortedAscending();
                        for(int i = 0; i < num.size(); i++){
                                cout << num[i] << " ";
                        }
                        cout << endl;
                }
                else if(input == "descend"){
                        num = number.GetSortedDescending();
                        for(int i = 0; i < num.size(); i++){
                                cout << num[i] << " ";
                        }
                        cout << endl;
                }
                else if(input == "max"){
                        int max = number.GetMax();
                        cout << max << endl;
                }
                else if(input == "min"){
                        int min = number.GetMin();
                        cout << min << endl;
                }
                else if(input == "quit"){
                        break;
                }
                else{
                        int numb = stoi(input);
                        number.AddNumber(numb);
                }
        }
        return 0;
}

