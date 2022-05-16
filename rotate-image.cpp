#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotateOuterLayer(vector<vector<int>> &a, int row) {
    int n = a.size() - 2 * row;
    // cout << "n " << n << endl;
    for (int i = 0; i < n - 1; i++) {

        int curr = a[row][i + row];
        int replacing = a[i + row][n - 1 + row];
        a[i + row][n - 1 + row] = curr;

        curr = replacing;
        replacing = a[n - 1 + row][n - 1 - i + row];
        a[n - 1 + row][n - 1 - i + row] = curr;

        curr = replacing;
        replacing = a[n - 1 - i + row][row];
        a[n - 1 - i + row][row] = curr;

        curr = replacing;
        a[row][i + row] = curr;
        // print2d(a);
    }
}
    void rotate(vector<vector<int>>& v) {
        for (int i = 0; i < v.size() / 2; i++) {
        // cout << v.size() - 2 * i << endl;
        rotateOuterLayer(v, i);
        // print2d(v);
    }

    }
};