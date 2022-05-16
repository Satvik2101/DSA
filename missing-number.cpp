#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int requiredSum = (n*(n+1))/2;
        int actualSum =0;
        for (int i :nums)
        {
            actualSum+=i;
        }
        return requiredSum-actualSum;
    }
};