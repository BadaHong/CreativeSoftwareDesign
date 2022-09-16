//this program shows how to create and use namespaces when they have the same name of function

#include <iostream>

using namespace std;

namespace first_space{
	void print(){
		cout << "Print from first space" << endl;
	}
}

namespace second_space{
	void print(){
		cout << "Print from second space" << endl;
	}
}
in main(){
	first_space::print();
	secondd_space::print();
	return 0;
}
