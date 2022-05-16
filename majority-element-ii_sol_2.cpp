#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cap = nums.size()/3;
        unordered_map<int,int> count;
        for (int i:nums){
            count[i]++;
        }
        vector<int> ans;
        for (auto it = count.begin();it!=count.end();it++){
            if (it->second > cap){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};