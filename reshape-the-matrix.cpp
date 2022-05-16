#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n =mat.size();
        int m = mat[0].size();
        
        if (m*n!=r*c){
            return mat;
        }
        
        vector<vector<int>> ans(r,vector<int>(c,0));
        int x =0, y =0;
        for(int i =0; i<n; i++)
            for(int j =0; j<m; j++)
            {   //cout<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
                ans[x][y] = mat[i][j];
                y++;
                if(y==c)
                {
                    x+=1;
                    y=0;
                }
                    
            }
        return ans;
    }
};