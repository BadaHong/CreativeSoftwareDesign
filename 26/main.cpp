#include <iostream>
#include <vector>

using namespace std;

class A{
        public:
                virtual string test(){
                        return "A::test()";
                }
};

class B: public A{
        public:
                virtual string test(){
                        return "B::test()";
                }
};

class C: public B{
        public:
                virtual string test(){
                        return "C::test()";
                }
};

int main(){
        vector<A*> arr;
        string input;
        while(1){
                cin >> input;
                if(input == "A"){
                        arr.push_back(new A);
                }
                else if(input == "B"){
                        arr.push_back(new B);
                }
                else if(input == "C"){
                        arr.push_back(new C);
                }
                else if(input == "quit"){
                        for(int i = 0; i < arr.size(); i++){
                                cout << arr[i]->test() << endl;
                        }
                        for(int i = 0; i < arr.size(); i++){
                                delete arr[i];
                        }
                        break;
                }
        }
        return 0;
}
