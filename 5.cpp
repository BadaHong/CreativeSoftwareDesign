//how to use functions related to string
#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1, str2;
	string nstr;
	cin >> str1;
	cin >> str2;
	nstr = str1 + str2;

	string first, last;
	first = nstr[0];
	last = nstr[nstr.length() - 1];

	cout << nstr << endl;
	cout << first << endl;
	cout << last << endl;
	return 0;
}
