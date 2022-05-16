#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = n-1;
        int ans = 0;
        while (left<right){
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if (leftMax < rightMax){
                ans += max(0,leftMax - height[left]);
                left++;
            }else{
                ans += max(0,rightMax - height[right]);
                right--;
            }
            
        }
        return ans;
    }
};
