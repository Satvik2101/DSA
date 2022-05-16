#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for (int i = 1;i<n;i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        int start = nums[n-1];
        for (int i = n-2;i>=0;i--){
            ans[i]*=start;
            start *= nums[i];
        }
        return ans;
    }
};