//
// Created by Uday B K on 29/07/20.
//

#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>&,vector<int>&,int);
int knapsack_util(vector<int>&,vector<int>&,int,int);

int main() {
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int capacity = 7;
    int max_profit = knapsack(profits,weights,capacity);
    cout<<max_profit<<"\n";
}

int knapsack(vector<int>& profits , vector<int>& weights,int capacity) {
    return knapsack_util(profits,weights,capacity,0);
}

int knapsack_util(vector<int>&profits,vector<int>&weights,int capacity,int index) {
    if (capacity <= 0 || index >= weights.size())
        return 0;

    //including element
    int include_profit = 0;
    if (weights[index] <= capacity) {
        include_profit = profits[index] +
                knapsack_util(profits,weights,capacity - weights[index] ,index + 1);
    }

    //excluding element
    int exclude_profit = knapsack_util(profits,weights,capacity,index+1);
    return max(include_profit,exclude_profit);
}