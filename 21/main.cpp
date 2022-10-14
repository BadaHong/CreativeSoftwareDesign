#include <iostream>
#include <vector>
#include <string>
#include "message.h"

using namespace std;

int main(){
        MessageBook book;
        string input;
        while(1){
                cin >> input;
                int num;
                if(input == "add"){
                        string mess;
                        cin >> num;
                        getline(cin >> ws, mess);
                        book.MessageBook::AddMessage(num, mess);
                }
                else if(input == "delete"){
                        cin >> num;
                        book.MessageBook::DeleteMessage(num);
                }
                else if(input == "print"){
                        cin >> num;
                        cout << book.MessageBook::GetMessage(num) << endl;
                }
                else if(input == "list"){
                        vector<int> vec = book.MessageBook::GetNumbers();
                        for(int i = 0; i < vec.size(); i++){
                                cout << vec[i] << ": " << book.MessageBook::GetMessage(vec[i]) << endl;
                        }
                }
                else if(input == "quit"){
                        break;
                }
        }
        return 0;
}

