//
// Created by Uday B K on 30/07/20.
//

#include <iostream>
#include <vector>
using namespace std;

bool can_partition_possible(vector<int>&);
bool can_partition_util(vector<int>&,int,int);


int main() {
    vector<int> num = {1, 2, 3, 4};
    cout<<can_partition_possible(num);
}


bool can_partition_possible(vector<int>&num) {
    int sum = 0;
    for (int i : num) {
        sum+=i;
    }
    int half = sum/2;
    return can_partition_util(num,0,half);
}

bool can_partition_util(vector<int>&num , int index , int sum) {

    //base cases for recursion
    if (sum == 0)
        return true;

    if (index >= num.size() || num[index] > sum)
        return false;

    cout<<index<<" "<<sum<<"\n";

    //include case
    if (num[index] <= sum)
        if (can_partition_util(num , index + 1 , sum - num[index]))
            return true;

    //exclude case
    return can_partition_util(num , index + 1 , sum);


}