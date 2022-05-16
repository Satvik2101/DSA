#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0];
        int maxVal = nums[0];
        int ans = nums[0];
        for (int i=1;i<n;i++){
            if (nums[i]<0){
                swap(minVal,maxVal);
            }
            minVal = min(nums[i], minVal*nums[i]);
            maxVal = max(nums[i],maxVal*nums[i]);
            ans = max(ans,maxVal);
        }
        return ans;
        
    }
};