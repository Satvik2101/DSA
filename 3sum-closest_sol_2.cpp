#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int i = 0;
        int j =1;
        int k = len -1;
        int closest = nums[i]+nums[j]+nums[k];
        while (i<len-2){
            int newTarget = target - nums[i];
            
            int sum = nums[j] + nums[k];
            int difference = newTarget - sum;
            if (difference == 0){
                return nums[i]+nums[j]+nums[k];
            }
            if (difference>0){
                j++;
            } else{
                k--;
            }
            if (abs(closest-target)>abs(sum+nums[i]-target)){
                closest = sum+nums[i];
            }
            if (j>=k){
                i++;
                j=i+1;
                k=len-1;
            }
        }
        return closest;
    }
};