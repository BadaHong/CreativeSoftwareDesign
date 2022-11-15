#include <iostream>
#include <string>
#include "my_string.h"

using namespace std;

int main(){
        MyString a, b, c;
        string input;
        while(1){
                cin >> input;
                if(input == "new"){
                        cout << "enter a" << endl;
                        cin >> a;
                        cout << "enter b" << endl;
                        cin >> b;
                }
                else if(input == "c="){
                        cin >> input;
                        string temp = input;
                        cin >> input;
                        if(input == "+"){
                                cin >> input;
                                string temp2 = input;
                                if(temp == "a"){
                                        if(temp2 == "a"){
                                                c = a.operator+(a);
                                        }
                                        else if(temp2 == "b"){
                                                c = a.operator+(b);
                                        }
                                }
                                else if(temp == "b"){
                                        if(temp2 == "a"){
                                                c = b.operator+(a);
                                        }
                                        else if(temp2 == "b"){
                                                c = b.operator+(b);
                                        }
                                }
                        }
                        else if(input == "*"){
                                cin >> input;
                                if(temp == "a"){
                                        c = a * stoi(input);
                                }
                                else if(temp == "b"){
                                        c = b * stoi(input);
                                }
                        }
                }
                else if(input == "print"){
                        cin >> input;
                        if(input == "a"){
                                cout << a;
                        }
                        else if(input == "b"){
                                cout << b;
                        }
                        else if(input == "c"){
                                cout << c;
                        }
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}

