#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> countSum;
        int sum = 0;
        int ans = 0;
        countSum.insert({0,1});
        for (int num:nums){
            sum+=num;
            ans += countSum[sum-k];
            countSum[sum]++;

        }
        return ans;
       
    }
};