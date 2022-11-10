#include <iostream>
#include <vector>

using namespace std;

class B{
        public:
                virtual ~B(){}
};

class C: public B{
        public:
                void test(){cout << "C::test()" << endl;}
};

class D: public B{
        public:
                void test(){cout << "D::test()" << endl;}
};

int main(){
        vector<B*> arr;
        while(1){
                string input;
                cin >> input;
                if(input == "B"){
                        arr.push_back(new B);
                }
                else if(input == "C"){
                        arr.push_back(new C);
                }
                else if(input == "D"){
                        arr.push_back(new D);
                }
                else if(input == "0"){
                        for(int i = 0; i < arr.size(); i++){
                                C* pd = dynamic_cast<C*>(arr[i]);
                                if(pd){
                                        pd->test();
                                }
                                D* pd2 = dynamic_cast<D*>(arr[i]);
                                if(pd2){
                                        pd2->test();
                                }
                        }
                        for(int i = 0; i < arr.size(); i++){
                                delete arr[i];
                        }
                        break;
                }
        }
        return 0;
}
