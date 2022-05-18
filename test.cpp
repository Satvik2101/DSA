#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// kbx2157
using namespace std;

bool comp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
int solve(vector<vector<int>> &intervals) {
    int ans = 0;
    if (intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), comp); // custom comperator is
                                                    // used.
    vector<int> prev = intervals[0];

    for (vector<int> i : intervals) {
        if (i == intervals[0])
            continue;
        if (prev[1] > i[0]) {
            ans++; // we dont update previous, because i[1] will be grater then
                   // prev[1]
            cout << prev[0] << " " << prev[1] << " " << i[0] << " " << i[1]
                 << endl;
        } else
            prev = i; // we want the end point to be minimum
    }
    return ans;
}

int main() {

    vector<vector<int>> v = {
        {1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13},
    };
    cout << solve(v);
    return 0;
}