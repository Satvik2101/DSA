#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo =0 ;
        int hi = nums.size()-1;
        int first = nums[0];
        int last = nums[nums.size()-1];
        if (last>first)return first;
        while (lo<hi){
            int mid = (lo+hi)/2;
            if (nums[mid]>=first)lo=mid+1;
            else hi=mid;
        }
        return nums[lo];
    }
};