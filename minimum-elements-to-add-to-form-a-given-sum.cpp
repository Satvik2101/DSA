#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int i :nums)
            sum+=i;
        long long diff = abs(goal-sum);
        
        return diff/limit + (diff%limit!=0);
    }
};