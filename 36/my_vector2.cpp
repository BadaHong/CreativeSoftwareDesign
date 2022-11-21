#include <iostream>
#include <string>
#include "my_vector2.h"

using namespace std;

MyVector2::MyVector2(){}

MyVector2::MyVector2(int length){
        this->length = length;
        a = new double[length];
}

MyVector2::MyVector2(const MyVector2& mv){
        length = mv.length;
        a = new double[length];
        for(int i = 0; i < length; i++){
                a[i] = mv.a[i];
        }
        cout << "(copy constructor)" << endl;
}

MyVector2::~MyVector2(){
        delete[] a;
}

MyVector2& MyVector2::operator=(const MyVector2& b){
        length = b.length;
        a = new double[length];
        for(int i = 0; i < length; i++){
                a[i] = b.a[i];
        }
        cout << "(assignment operator)" << endl;
        return *this;
}

MyVector2 MyVector2::operator+(const MyVector2& b){
        MyVector2 temp(b.length);
        for(int i = 0; i < length; i++){
                temp.a[i] = a[i] + b.a[i];
        }
        return temp;
}

MyVector2 MyVector2::operator-(const MyVector2& b){
        MyVector2 temp(b.length);
        for(int i = 0; i < length; i++){
                temp.a[i] = a[i] - b.a[i];
        }
        return temp;
}

MyVector2 MyVector2::operator+(const int b){
        MyVector2 temp(length);
        for(int i = 0; i < length; i++){
                temp.a[i] = a[i] + b;
        }
        return temp;
}

MyVector2 MyVector2::operator-(const int b){
        MyVector2 temp(length);
        for(int i = 0; i < length; i++){
                temp.a[i] = a[i] - b;
        }
        return temp;
}

ostream& operator<<(ostream& out, MyVector2& b){
        for(int i = 0; i < b.length; i++){
                out << b.a[i] << " ";
        }
        return out;
}

istream& operator>>(istream& in, MyVector2& b){
        for(int i = 0; i < b.length; i++){
                in >> b.a[i];
        }
        return in;
}

