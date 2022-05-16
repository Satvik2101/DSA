#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0;i<n;i++){
            if (nums[i]==INT_MIN) continue;
            int correctPos = nums[i]-1;
            while (nums[i]>=1 && nums[i]<=n && nums[i]!=nums[correctPos]){
                swap(nums[i],nums[correctPos]);
                correctPos = nums[i]-1;
            }
        }
        for (int i =0;i<n;i++){
            if (nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};