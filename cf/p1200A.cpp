//
// Created by Uday B K on 17/08/20.
//
#include <iostream>
#include <vector>
using namespace std;

void findARoom(vector<int>&arr,char,int);

void printArray(vector<int>&arr) {
    for (int i : arr) {
        cout<<i;
    }
}

int main() {
    int len;cin>>len;
    string events;cin>>events;
    vector<int>arr = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < len; i++) {

        if (events[i] == 'L') {
            findARoom(arr, 'L', INT_MAX);
        } else if (events[i] == 'R') {
            findARoom(arr,'R',INT_MAX);
        } else {
            findARoom(arr,'I',events[i] - 48);
        }

    }
    printArray(arr);
}


void findARoom(vector<int>&arr , char direction , int position) {

    switch (direction) {
        case 'L':
            for (int i = 0 ; i < 10; i++) {
                if (arr[i] == 0) {
                    arr[i] = 1;
                    break;
                }
            }
            break;

        case 'R':
            for (int i = 9 ; i >=0 ; i--) {
                if (arr[i] == 0) {
                    arr[i] = 1;
                    break;
                }
            }
            break;

        case 'I':
            if (position != INT_MAX)
                arr[position] = 0;

        default:
            break;
    }

}

