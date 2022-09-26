//this program will print out the magic square of the number of multiples of 4. The code shows how to do create and use dynamically allocated memory and create 2D array using it. Also, it shows how to pass array using reference.

#include <iostream>

using namespace std;

void magicSquare(int**& arr, int N){
        int a1[N][N], a2[N][N];
        int num1 = 1, num2 = N*N;
	
	//adding magic square integers to each arrray        
	for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        a1[i][j] = num1++;
                        a2[i][j] = num2--;
                }
        }

	//adjusting the original magic square with corresponding integers using a1 and a2
        int r1 = N/4, r2 = N/2;
        for(int row = 0; row < N; row++){
                if((row >= 0 && row < r1) || (row >= r1+r2 && row < N)){
                        for(int col = 0; col < N; col++){
                                if((col >= 0 && col < r1) || (col >= r1+r2 && col < N)){
                                        arr[row][col] = a1[row][col];
                                }
                                else{
                                        arr[row][col] = a2[row][col];
                                }
                        }
                }
                else{
                        for(int col = 0; col < N; col++){
                                if((col >= 0 && col < r1) || (col >= r1+r2 && col < N)){
                                        arr[row][col] = a2[row][col];
                                }
                                else{
                                        arr[row][col] = a1[row][col];
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
                arr[i] = new int[N];
        }
        magicSquare(arr, N);
        for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                        cout << arr[i][j] << " ";
                }
                cout << endl;
        }
	
	//deleting dynamically allocated memory for each colum and row
        for(int i = 0; i < N; i++){
                delete[] arr[i];
        }
        delete[] arr;
        return 0;
}
