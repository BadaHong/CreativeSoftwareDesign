//function overloading

#include <iostream>

using namespace std;

int add(int a, int b){
	return a + b;
}

string add(string a, string b){
	return a + "-" + b;
}

float add(float a, float b = 0.9){
	return a + b;
}

int main(){
	int num1, num2;
	string str1, str2;
	float a;
	cin >> num1 >> num2 >> str1 >> str2 >> a;
	cout << add(num1, num2) << endl;
	cout << add(str1, str2) << endl;
	cout << add(a) << endl;
	return 0;
}
