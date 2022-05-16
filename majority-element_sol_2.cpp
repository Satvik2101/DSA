#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);
    }
};