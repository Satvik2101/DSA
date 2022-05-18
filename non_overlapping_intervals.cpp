#include <bits/stdc++.h>
// kbx2157
using namespace std;
// Question Link: https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
    static bool comp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        vector<int> &interval = intervals[0];
        int count = 1;
        for (vector<int> &v : intervals) {
            if (v[0] >= interval[1]) {
                count++;
                interval = v;
            }
        }
        return intervals.size() - count;
    }
};