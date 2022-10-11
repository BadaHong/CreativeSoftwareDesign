#include <iostream>
#include <vector>
#include <algorithm>
#include "sorted.h"

SortedArray::SortedArray(){
}

SortedArray::~SortedArray(){
        numbers_.clear();
}

void SortedArray::AddNumber(int num){
        numbers_.push_back(num);
}

vector<int> SortedArray::GetSortedAscending(){
        sort(numbers_.begin(), numbers_.end());
        return numbers_;
}

vector<int> SortedArray::GetSortedDescending(){
        sort(numbers_.rbegin(), numbers_.rend());
        return numbers_;
}

int SortedArray::GetMin(){
        return *min_element(numbers_.begin(), numbers_.end());
}

int SortedArray::GetMax(){
        return *max_element(numbers_.begin(), numbers_.end());
}

