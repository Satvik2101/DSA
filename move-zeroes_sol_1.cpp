#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last =0;
        for (int i =0 ;i<nums.size();i++)
        {
            if (nums[i]!=0)
            {
             nums[last]=nums[i];
             last++;
             }
        }
        for (int i = last;i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
};