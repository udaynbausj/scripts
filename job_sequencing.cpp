//
// Created by Uday B K on 06/05/20.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct job_details {
    int id , dead_line , profit;
};

bool compare(job_details a , job_details b) {
    return a.profit > b.profit;
}

int max_profit(vector<job_details>&details , int len , int max_deadline) {
    int profit = details[0].profit;
    for (int i = 1 ; i < max_deadline ; i++ ) {
        if (details[i].dead_line > i) {
            profit+=details[i].profit;
        }
    }
    return profit;
}

int main() {
    int test;
    cin>>test;
    while(test--) {
        int jobs;
        cin>>jobs;
        vector<job_details>details(jobs);
        int max_deadline = INT_MIN;
        for (int i = 0 ; i < jobs; i++ ) {
            cin>>details[i].id>>details[i].dead_line>>details[i].profit;
            if (max_deadline < details[i].dead_line)
                max_deadline = details[i].dead_line;
        }
        sort(details.begin(),details.end(),compare);
        cout<<max_profit(details,jobs,max_deadline)<<"\n";
    }
}
