#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int ans = 0;
        int sum = 0;
        for (int num:nums){
            sum+=num;
            ans+= mp[sum-k];
            mp[sum]++;
        }
        return ans;
        
    }
};