#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lastEvenAt = 0;
        for (int i = 0;i<nums.size();i++){
            if (!(nums[i]&1)){
                swap (nums[i],nums[lastEvenAt++]);
            }
        }
        return nums;
    }
};