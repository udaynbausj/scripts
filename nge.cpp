//
// Created by Uday B K on 15/05/20.
//

#include <iostream>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

void nge_right(ll* arr , int size) {
    int len = size;
    stack<int>s;
    s.push(arr[len - 1]);
    vector<int>res;
    res.push_back(-1);
    for (int i = size -2 ; i>= 0; i-- ) {
        int current_element = arr[i];
        while(!s.empty() && s.top() <= current_element) {
            s.pop();
        }
        if (s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());
        s.push(current_element);
    }

    for (auto & num : res) {
        cout<<num<<"\n";
    }
}

int main() {
    ll arr[] = {11,13,21,3};
    nge_right(arr , 4);
}