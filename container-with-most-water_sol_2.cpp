#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    
   
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int ans = 0;
        while (i<j){
            ans = max(ans, (j-i)*min(height[j],height[i]));
            if (height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};