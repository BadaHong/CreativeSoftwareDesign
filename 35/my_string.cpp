#include <iostream>
#include "my_string.h"

using namespace std;

MyString MyString::operator+(const MyString& b){
        MyString temp;
        temp.str = str + b.str;
        return temp;
}

MyString MyString::operator*(const int b){
        MyString temp;
        for(int i = 0; i < b; i++){
                if(i == 0){
                        temp.str = str;
                }
                else{
                        temp.str += str;
                }
        }
        return temp;
}

ostream& operator<<(ostream& out, MyString& my_string){
        out << my_string.str << endl;
        return out;
}

istream& operator>>(istream& in, MyString& my_string){
        in >> my_string.str;
        return in;
}
