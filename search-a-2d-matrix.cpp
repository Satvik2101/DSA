#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i= 0,j=m-1;
        
        while (i>=0 && j>=0 && i<n &&j<m){
            if (matrix[i][j]==target) return true;
            
            if (matrix[i][j]<target)i++;
            else j--;
        }
        return false;
    }
    
};