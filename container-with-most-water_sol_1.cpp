#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size()-1;
        int area =0;
        while (lo<hi){
            area = max(area, (hi-lo)*min(height[lo],height[hi]));
            if (height[lo]<height[hi])lo++;
            else hi--;
        }
        return area;
    }
};