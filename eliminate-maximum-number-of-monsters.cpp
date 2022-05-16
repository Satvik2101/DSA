#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> times;
        for (int i = 0;i<dist.size();i++){
            float val = (float)dist[i]/(float)speed[i];
            times.push_back(val);
        }
        sort(times.begin(),times.end());
        int count = 0;
        for (int i =0;i<times.size();i++){
            if (times[i]<=count) return count;
            count++;
        }
        return dist.size();
    }
};