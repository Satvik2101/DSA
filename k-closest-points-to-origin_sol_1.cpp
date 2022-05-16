#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int,vector<int>> pointAt;
        for (vector<int> &point:points){
            int distance = point[0]*point[0] +point[1]*point[1];
            pointAt.insert({distance,point});
        }
        int i=0;
        vector<vector<int>> ans(k);
        for (auto item:pointAt){
            if (i>=k)break;
            ans[i] = item.second;
            i++;
        }
        return ans;
    }
};