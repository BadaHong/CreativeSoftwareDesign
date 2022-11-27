#include <iostream>
#include "list.h"

using namespace std;

int main(){
	int array[5] = {12, 7, 9, 21, 13};
	List<int> li(array, 5);
	cout << li << endl;

	li.pop_back();
	cout << li << endl;

	li.push_back(15);
	cout << li << endl;

	li.pop_front();
	cout << li << endl;

	li.push_front(8);
	cout << li << endl;

	li.insert_at(4, 19);
	cout << li << endl;

	li.remove_at(1);
	cout << li << endl;

	return 0;
}
