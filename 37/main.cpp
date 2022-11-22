#include <iostream>

using namespace std;

template <typename T>
void myswap(T& a, T& b){
        T temp;
        temp = a;
        a = b;
        b = temp;
}

int main(){
        int a, b;
        double c, d;
        string e, f;
        for(int i = 0; i < 3; i++){
                if(i == 0){
                        cin >> a >> b;
                        myswap<int>(a, b);
                        cout << "After calling myswap(): " << a << " " << b << endl;

                }
                else if(i == 1){
                        cin >> c >> d;
                        myswap<double>(c, d);
                        cout << "After calling myswap(): " << c << " " << d << endl;

                }
                else if(i == 2){
                        cin >> e >> f;
                        myswap<string>(e, f);
                        cout << "After calling myswap(): " << e << " " << f << endl;

                }
        }
        return 0;
}

