#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len  = nums.size();
        int first = 0;
        int second = 1;
        int third = 2;
        int fourth = len -1;
        set<vector<int>> ans;
        while (first<len-3){
            long long sum = (long long)nums[first]+(long long)nums[second] + (long long)nums[third]+(long long)nums[fourth];
            
            if (sum<target){
                third++;
            } else if (sum>target){
                fourth--;
            }
            else{
                ans.insert({nums[first],nums[second],nums[third],nums[fourth]});
                third++;
                fourth--;
                
            }
            
            if (third>=fourth){
                second++;
                third= second+1;
                fourth = len -1;
            }
            if (second>=len-2){
                first++;
                second= first+1;
                third = second+1;
                fourth = len-1;
            }
        }
        
        vector<vector<int>> vAns;
        for (vector<int> v :ans){
            vAns.push_back(v);
        }
        return vAns;
    }
};

