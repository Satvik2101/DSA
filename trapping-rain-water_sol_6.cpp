#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
     int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> minH(n,0);
        
        int currMax = 0;
        for (int i = 0;i<n;i++){
            left[i] = currMax;
            currMax = max(currMax,height[i]);
        }
        currMax = 0;
        for (int i = n-1;i>=0;i--){
            // right[i] = currMax;
            minH[i] = min(left[i],currMax);
            currMax = max(currMax,height[i]);
        }
        int ans = 0;
        for (int i = 0;i<n;i++){
            ans += max(0,minH[i]-height[i]);
        }
        return ans;
    }
};
