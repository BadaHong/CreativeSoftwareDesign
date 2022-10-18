#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "setfunc.h"

using namespace std;

int main(){
        while(1){
                string input;
                set<int> result;
                getline(cin >> ws, input);
                set<int> set1;
                set<int> set2;
                string s1 = "";
                string s2 = "";
                string op;
                int check = 0;
                if(input == "0"){
                        break;
                }
                if(input.substr(0, 1) == "{"){
                        string temp = input;
                        input.erase(0, 2);
                        while(1){
                                int index = input.find(" ");
                                string temp = input.substr(0, index);
                                if(temp == "{" || temp == "}"){
                                        check = 1;
                                }
                                else if(temp == "+" || temp == "-" || temp == "*"){
                                        op = temp;
                                }
                                else if(check == 0){
                                        s1 = s1 + temp + " ";
                                }
                                else if(check == 1){
                                        s2 = s2 + temp + " ";
                                }
                                input.erase(0, index);
                                if(input.substr(0, 1) == " "){
                                        input.erase(0, 1);
                                }
                                if(input.length() == 0){
                                        break;
                                }
                        }
                        set1 = parseSet(s1);
                        set2 = parseSet(s2);
                        check = 0;
                }
                if(op == "+"){
                        result = getIntersection(set1, set2);
                }
                else if(op == "-"){
                        result = getDifference(set1, set2);
                }
                else if(op == "*"){
                        result = getUnion(set1, set2);
                }
                printSet(result);
                cout << endl;
        }
        return 0;
}

