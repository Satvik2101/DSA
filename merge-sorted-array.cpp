#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m,nums1.end());
       for (int i:nums2)
       {
           nums1.push_back(i);
       }
        sort(nums1.begin(),nums1.end());
    }
};