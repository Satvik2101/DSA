#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = nums[0];
        
        for (int i :nums){
            currSum +=i;
            maxSum = max(maxSum,currSum);
            if (currSum<0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};