#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	int* arr = new int[N];
	int num;
	for(int i = 0; i < N; i++){
		cin >> num;
		arr[i] = num;
	}

	int target;
	int count = 0;
	cin >> target;
	for(int j = 0; j < N; j++){
		if(arr[j] == target){
			count++;
		}
	}
	cout << "target value: " << target << endl;
	cout << "target count: " << count << endl;
	delete[] arr;
	return 0;
}
