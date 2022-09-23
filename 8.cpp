//This program will print out the magic square of the odd number. This code shows how to create and use dynamically allocated memory and 2D array using it. This also shows how to pass array using reference to a function.
#include <iostream>

using namespace std;

void magicSquare(int**& arr, int N){
	int num = 1; row = 0; col = N/2;
	arr[row][col] = num++;
	while(num <= N*N){
		if(row == 0){
			if(col == N-1){
				row++;
				arr[row][col] = num++;
			}
			else{
				row = N-1;
				col++;
				arr[row][col] = num++;	
			}
		}
		else if(col == N-1){
			row--;
			col = 0;
			arr[row][col] = num++;
		}
		else{
			row--;
			col++;
			if(arr[row][col] != 0){
				row = row + 2;
				col--;
				arr[row][col] = num++;
			}
			else{
				arr[row][col] = num++;
			}
		}
	}
}

int main(){
	int N;
	cin >> N;
	if(N < 3 || N % 2 == 0){
		return 0;
	}
	int** arr = new int*[N];
	for(int i = 0; i < N; i++){
		arr[i] = new int[N];
		for(int j = 0; j < N; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < N; i++){
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
