#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "message.h"

using namespace std;

MessageBook::MessageBook(){
}

MessageBook::~MessageBook(){
        messages_.clear();
}

void MessageBook::AddMessage(int number, const string& message){
        messages_[number] = message;
}

void MessageBook::DeleteMessage(int number){
        messages_.erase(number);
}

vector<int> MessageBook::GetNumbers(){
        vector<int> v;
        for(map<int, string>::iterator it = messages_.begin(); it != messages_.end(); it++){
                v.push_back(it->first);
        }
        return v;
}

const string& MessageBook::GetMessage(int number){
        return messages_[number];
}
