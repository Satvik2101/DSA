#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size();
        if (minLen == 1){
            if (nums[0]>=target) return 1;
            return 0;
        }
        int i =0;
        int j = 1;
        int curSum = nums[i] + nums[j];
        bool greaterAchieved = false;
        while (i<j){
            if (nums[i]>=target || nums[j]>=target){
                return 1;
            }
            if (curSum<target){
                j++;
                if (j>=nums.size()){
                    if (!greaterAchieved){
                        return 0;
                    }
                    return minLen;
                }
                curSum += nums[j];
            }else{
                minLen = min(minLen,j-i+1);
                greaterAchieved = true;
                curSum-=nums[i];
                i++;
                if (i>=nums.size()){
                    if (!greaterAchieved){
                        return 0;
                    }
                    return minLen;
                }
                //curSum+=nums[i];
            }
        }
        cout<<curSum;
        if (!greaterAchieved){
            return 0;
        }
        return minLen;
    }
};