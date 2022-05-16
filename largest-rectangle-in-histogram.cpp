#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea =0;
        int i;
        for (i = 0;i<n;i++){
            if (s.empty() || (heights[i]>=heights[s.top()])) s.push(i);
            else{
                int height = heights[s.top()];
                s.pop();
                int width = s.empty()?i:i-1-s.top();
                maxArea = max(height*width,maxArea);
                i--;
            }
        }
        
        while (!s.empty()){
                int height = heights[s.top()];
                s.pop();
                int width = s.empty()?i:i-1-s.top();
                maxArea = max(height*width,maxArea);
        }
        return maxArea;
    }
};