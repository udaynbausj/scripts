//
// Created by Uday B K on 29/07/20.
//

#include <iostream>
#include <vector>

using namespace std;

//func signatures
int knapsack_inf(vector<int>&,vector<int>&,int);
int knapsack_util(vector<int>&,vector<int>&,int,int);

int main() {
    vector<int> profits = {15, 50, 60, 90};
    vector<int> weights = {1, 3, 4, 5};
    int capacity = 8;
    int profit = knapsack_inf(profits,weights,capacity);
    cout<<profit<<"\n";
}

int knapsack_inf(vector<int>&profits,vector<int>&weights,int capacity) {
    return knapsack_util(profits,weights,capacity,0);
}

int knapsack_util(vector<int>&profits,vector<int>&weights,int capacity,int index) {

    if (index >= weights.size() || weights[index] > capacity)
        return 0;


    //including profit
    int inc_profit = 0;

    if (weights[index] <= capacity) {
        inc_profit = profits[index] + knapsack_util(profits,weights,capacity - weights[index],index);
    }

    int exc_profit = knapsack_util(profits,weights,capacity,index+1);

    return max(inc_profit,exc_profit);
}