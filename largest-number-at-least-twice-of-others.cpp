#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxElement = nums[0];
        int maxIndex = 0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]>maxElement){
                maxElement = nums[i];
                maxIndex = i;
            }
        }
        for (int i :nums){
            if (i==maxElement) continue;
            if (2*i > maxElement){
                return -1;
            }
        }
        return maxIndex;
    }
};