//this program will print out the magic square of the number of multiples of 4. The code shows how to do create and use dynamically allocated memory and create 2D array using it. Also, it shows how to pass array using reference.

#include <iostream>

using namespace std;

void magicSquare(int**& arr, int N){
	int a1[N][N], a2[N][N];
	int num1 = 1, num2 = N*N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			a1[i][j] = num1++;
			a2[i][j] = num2--;
		}
	}
	inr r1, r2;
	r1 = N/4;
	r2 = N/2;
	int row = 0; col = 0;
	while(row < N && col < N){
		for(int row = 0; row < N; row++){
			if((row >= 0 && row < r1 || (row > r1+r2 && row < r1+r2+r1)){
				for(int col = 0; col < N; col++){
					if((col >= 0 && col < r1) || (col > r1+r2 && col < r1+r2+r1)){
						arr[row][col] = a1[row][col];
					}
					else{
						arr[row][col] = a2[row][col];
					}
					col++;
				}
			}
			else{
				for(int col = 0; col < N; col++){
                                        if((col >= 0 && col < r1) || (col > r1+r2 && col < r1+r2+r1)){
                                                arr[row][col] = a1[row][col];
                                        }
                                        else{
                                                arr[row][col] = a2[row][col];
                                        }
                                        col++;
                                }
			}
		}
	}
}
int main(){
	int N;
	cin >> N;
	if(N % 4 != 0){
		return 0;
	}
	int** arr = new int*[N];
	for(int i = 0; i < N; i++){
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
