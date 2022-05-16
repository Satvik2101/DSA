#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/rotate-array

class Solution {
public:
    
    void reversePart(vector<int> &nums,int startIndex){
        reverse(nums.begin()+startIndex,nums.end());
    }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k= k%n;
        reversePart(nums,n-k);
        reversePart(nums,0);
        reversePart(nums,k);
    }
};