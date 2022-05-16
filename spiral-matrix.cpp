#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        int iMin=0,jMin=0,iMax = n-1,jMax=m-1;
        vector<int> ans;
         while (iMin < n && jMin < m && iMin <= iMax && jMin <= jMax) {
        int i = iMin;
        int j = jMin;

        // Top l to r

        for (; j <= jMax; j++) {
            ans.push_back(matrix[i][j]);
        }
        j = jMax;
        i++;
        for (; i <= iMax; i++) {
            ans.push_back(matrix[i][j]);
        }
        i = iMax;
        j--;
        for (; iMin != iMax && j >= jMin; j--) {
            ans.push_back(matrix[i][j]);
        }
        j = jMin;
        i--;
        for (; jMin != jMax && i >= iMin + 1; i--) {
            ans.push_back(matrix[i][j]);
        }

        iMin++;
        jMin++;
        iMax--;
        jMax--;
    }
        return ans;
    }
};