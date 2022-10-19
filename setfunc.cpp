#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"

using namespace std;

set<int> parseSet(const string& str){
        set<int> s;
        string str2 = str;
        int index;
        while(1){
                index = str2.find(" ");
                string temp = str2.substr(0, index);
                s.insert(stoi(temp));
                str2.erase(0, index);
                if(str2.substr(0, 1) == " "){
                        str2.erase(0, 1);
                }
                if(str2.length() == 0){
                        break;
                }
        }
        return s;
}

void printSet(const set<int>& set0){
        cout << "{ ";
        for(set<int>::iterator it = set0.begin(); it != set0.end(); it++){
                cout << *it << " ";
        }
        cout << "}";
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1){
        set<int> s;
        s.insert(set0.begin(), set0.end());
        for(set<int>::iterator it = set0.begin(); it != set0.end(); it++){
                for(set<int>::iterator it2 = set1.begin(); it2 != set1.end(); it2++){
                        if(*it == *it2){
                                s.erase(*it2);
                        }
                }
        }
        s.insert(set1.begin(), set1.end());
        return s;
}

set<int> getUnion(const set<int>& set0, const set<int>& set1){
        set<int> s;
        for(set<int>::iterator it = set0.begin(); it != set0.end(); it++){
                for(set<int>::iterator it2 = set1.begin(); it2 != set1.end(); it2++){
                        if(*it == *it2){
                                s.insert(*it);
                        }
                }
        }
        return s;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1){
        set<int> s;
        s.insert(set0.begin(), set0.end());
        for(set<int>::iterator it = set0.begin(); it != set0.end(); it++){
                for(set<int>::iterator it2 = set1.begin(); it2 != set1.end(); it2++){
                        if(*it == *it2){
                                s.erase(*it);
                        }
                }
        }
        return s;
}

