//
// Created by Uday B K on 30/07/20.
//

#include <iostream>
#include <vector>

using namespace std;

int jumps_to_reach_end(vector<int>&);
int jumps_to_reach_end_util(vector<int>&,int);

int main() {
    vector<int> jumps = {2, 1, 1, 1, 4};
    cout<<jumps_to_reach_end(jumps);
}

int jumps_to_reach_end(vector<int>&jumps) {
    return jumps_to_reach_end_util(jumps,0);
};

int jumps_to_reach_end_util(vector<int>&jumps , int index) {

   if (index == jumps.size()-1)
       return 0;

   jumps_to_reach_end_util(jumps[])

}