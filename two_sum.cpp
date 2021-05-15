#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            
            int element = nums[i];
            int diff = target - element;
            if (mp.find(diff) != mp.end()) {
                return {i,mp[diff]};
            }

            mp[element] = i;

        }

        return {};
        
    }
};