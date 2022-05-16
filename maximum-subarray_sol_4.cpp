#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        int sum=0;
        int maxSoFar=INT_MIN;
        for (int i=0;i<nums.size();i++)
        {   
            sum+=nums[i];
           
            if (maxSoFar<sum)
                maxSoFar=sum;
             if (sum<0)
                sum =0;
        }
        return maxSoFar;*/
        int currentSum = 0;
    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
        
    }
    return maxSum;
    }
};