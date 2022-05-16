#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> v;
        int i =0;
        int j =0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else
                i++;
            
        }

             return v;
    }
};