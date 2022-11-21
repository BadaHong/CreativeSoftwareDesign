#include <iostream>
#include <string>
#include "my_vector2.h"

using namespace std;

int main(){
        MyVector2* a = NULL;
        MyVector2* b = NULL;
        MyVector2* c = NULL;
        MyVector2* d = NULL;
        string input;
        string op = "copy";
        int len;
        while(1){
                cin >> input;
                if(input == "new"){
                        cin >> len;
                        a = new MyVector2(len);
                        b = new MyVector2(len);
                        cout << "enter a" << endl;
                        cin >> *a;
                        cout << "enter b" << endl;
                        cin >> *b;
                }
                else if(input == "set"){
                        cin >> input;
                        if(input == "copy"){
                                op = "copy";
                        }
                        else if(input == "assign"){
                                op = "assign";
                        }
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
                                                if(op == "copy"){
                                                        d = new MyVector2(*a + *a);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a + *a;
                                                }
                                        }
                                        else if(temp2 == "b"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*a + *b);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a + *b;
                                                }
                                        }
                                        else{
                                                if(op == "copy"){
                                                        d = new MyVector2(*a + stod(temp2));
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a + stod(temp2);
                                                }
                                        }
                                }else if(temp == "b"){
                                        if(temp2 == "a"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*b + *a);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b + *a;
                                                }
                                        }
                                        else if(temp2 == "b"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*b + *b);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b + *b;
                                                }
                                        }
                                        else{
                                                if(op == "copy"){
                                                        d = new MyVector2(*b + stod(temp2));
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b + stod(temp2);
                                                }
                                        }
                                }
                        }else if(input == "-"){
                                cin >> input;
                                string temp2 = input;
                                if(temp == "a"){
                                        if(temp2 == "a"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*a - *a);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a - *a;
                                                }
                                        }
                                        else if(temp2 == "b"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*a - *b);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a - *b;
                                                }
                                        }
                                        else{
                                                if(op == "copy"){
                                                        d = new MyVector2(*a - stod(temp2));
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *a - stod(temp2);
                                                }
                                        }
                                }
                                else if(temp == "b"){
                                        if(temp2 == "a"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*b - *a);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b - *a;
                                                }
                                        }
                                        else if(temp2 == "b"){
                                                if(op == "copy"){
                                                        d = new MyVector2(*b - *b);
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b - *b;
                                                }
                                        }
                                        else{
                                                if(op == "copy"){
                                                        d = new MyVector2(*b - stod(temp2));
                                                        c = new MyVector2(*d);
                                                }
                                                else if(op == "assign"){
                                                        c = new MyVector2();
                                                        *c = *b - stod(temp2);
                                                }
                                        }
                                }
                        }
                }else if(input == "print"){
                        cin >> input;
                        if(input == "a"){
                                cout << *a;
                        }
                        else if(input == "b"){
                                cout << *b;
                        }
                        else if(input == "c"){
                                cout << *c;
                        }
                        cout << endl;
                }
                else if(input == "quit"){
                        delete a;
                        delete b;
                        delete c;
                        delete d;
                        break;
                }
        }
        return 0;
}

