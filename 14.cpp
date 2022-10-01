#include <iostream>
#include <string>
#include "swap.h"

using namespace std;

void swapString(string& s1, string& s2){
        string temp = s1;
        s1 = s2;
        s2 = temp;
}

int main(){
        int n1, n2;
        string s1, s2;
        cin >> n1 >> n2 >> s1 >> s2;
        cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2 << endl;
        swapInt(n1, n2);
        swapString(s1, s2);
        cout << "n1: " << n1 << ", n2: " << n2 << ", s1: " << s1 << ", s2: " << s2 << endl;
        return 0;
}
