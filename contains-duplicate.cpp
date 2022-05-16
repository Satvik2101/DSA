#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector <int> soFar = {};
        for (int i:nums)
        {
            if (find(soFar.begin(),soFar.end(),i)!=soFar.end())return true;
            soFar.push_back(i);
        }
    
    return false;
    }
};