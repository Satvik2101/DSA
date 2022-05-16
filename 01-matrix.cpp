#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n==0)return mat;
        int m = mat[0].size();
        
        vector<vector<int>>dist (n,vector<int>(m,n+m-1));
        
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (mat[i][j] == 0) {
                    dist[i][j]=0;
                    continue;
                }
                if (i>0) dist[i][j] = min(dist[i][j],dist[i-1][j]+1);
                if (j>0) dist[i][j] = min(dist[i][j],dist[i][j-1]+1);
            }
        }
        for (int i = n-1;i>=0;i--){
            for (int j = m-1;j>=0;j--){
                // if (mat[i][j] == 0) dist[i][j]=0;
                if (i<n-1) dist[i][j] = min(dist[i][j],dist[i+1][j]+1);
                if (j<m-1) dist[i][j] = min(dist[i][j],dist[i][j+1]+1);
            }
        }
        return dist;
    }
};