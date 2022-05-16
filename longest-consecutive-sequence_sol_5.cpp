#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> elements(nums.begin(),nums.end());
        int maxCount = 0;
        for (int num:nums){
            if (elements.find(num-1)==elements.end()){
                int count = 1;
                int nextNum = num+1;
                while (elements.find(nextNum)!=elements.end()){
                    count++;
                    nextNum++;
                }
                maxCount = max(count,maxCount);
            }
        }
        return maxCount;
    }
};