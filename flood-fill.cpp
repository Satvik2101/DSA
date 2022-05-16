#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    int m;
    int sourceVal;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ans = image;
        n = ans.size();
        m = ans[0].size();
        //ans[sr][sc]= newColor;
        sourceVal = ans[sr][sc];
        if (sourceVal == newColor){
            return ans;
        }
        flood(sr,sc,sr,sc,newColor);
        return ans;
    }
    
    void flood(int i, int j, int sr,int sc, int newColor){
        if (ans[i][j] == sourceVal){
            ans[i][j]= newColor;
            if (i>0){
               // cout<<"i "<<i<<" ";
                if (sr!=i-1 || sc!=j)
                    flood(i-1,j,i,j,newColor);
            }
            if (i<n-1){
                //cout<<"i "<<i<<" ";
                if (sr!=i+1 || sc!=j)
                    flood(i+1,j,i,j,newColor);
            }
            if (j>0){
               // cout<<"j "<<j<<" ";
                if (sr!=i || sc!=j-1)
                    flood(i,j-1,i,j,newColor);
            }
            if (j<m-1){
                //cout<<"j "<<j<<" ";
                if (sr!=i || sc!=j+1)
                    flood(i,j+1,i,j,newColor);
            }
           // cout<<"x"<<endl;
        }
    }
};