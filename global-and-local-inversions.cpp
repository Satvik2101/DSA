#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0;i<n;i++){
            if (abs(nums[i]-i)>1){
                return false;
            }
        }
        return true;
       
    }
};