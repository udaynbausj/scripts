#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int target = 0;
        vector<vector<int>>result;
        unordered_map<string,bool>mp;
        string str;
        for( int i = 0 ; i < nums.size() ; i++) {
            unordered_set<int>s;
            for (int j = i+1 ; j < nums.size() ; j++) {
            
                if ( i != j) {
                    
                    int sum = nums[i] + nums[j];
                    if (s.find(-1 * sum) != s.end()) {

                        // sort here
                        vector<int> res = {-1 * sum, nums[i], nums[j]};
                        res = sort_array_of_size_3(res);
                        string final_str;
                        for (int k = 0 ; k < res.size() ; k++) {
                            final_str = final_str + to_string(res[k]);
                        }

                        if (mp.find(final_str) == mp.end()) {
                            result.push_back({-1 * sum, nums[i], nums[j]});
                            mp[final_str] = true;
                        }
                        
                    } else {
                        s.insert(nums[j]);
                    }

                }

            }

        }
        return result;
    }

    vector<int> sort_array_of_size_3(vector<int> arr) {
        if (arr[0] > arr[1])
            swap(arr[0], arr[1]);
        if (arr[0] > arr[2])
            swap(arr[0], arr[2]);
        if (arr[1] > arr[2])
            swap(arr[1], arr[2]);
        return arr;
    }

};