#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum =0;
        for (int i:nums)
        {
            sum = sum^i;
        }
        return sum;
    }
};