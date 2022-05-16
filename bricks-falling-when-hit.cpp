#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/bricks-falling-when-hit

class Solution {
public:
    vector<vector<int>> grid;
    int m,n;
    vector<pair<int,int>> directions={{-1,0},{0,-1},{0,1},{1,0}};

    vector<int> hitBricks(vector<vector<int>>& gr, vector<vector<int>>& hits) {
        this->grid = gr;
        m = grid.size();
        n = grid[0].size();
        
       // for (int i = 0;i<hits.size();i++){
       //     int x = hits[i][0];
       //     int y = hits[i][1];
       //     if (grid[x][y]==1) grid[x][y]=-1;
       // }
        for(int i=0;i<hits.size();i++)
            if(grid[hits[i][0]][hits[i][1]] == 1)
                grid[hits[i][0]][hits[i][1]] = -1;
        
        for (int i =0; i<grid[0].size();i++){
            markAndCountStable(0,i);
            // cout<<i<<" "<<grid[0][i]<<endl;
        }
        
        vector<int> ans(hits.size());
        for (int i = hits.size()-1; i>=0;i--){
            int x = hits[i][0];
            int y = hits[i][1];
            
            if (grid[x][y]==0) continue;
            
            grid[x][y]=1;
            
//             for (int i = 0;i<m;i++){
//                 for (int j = 0;j<n;j++){
//                     cout<<grid[i][j]<<" ";
//                 }
//                 // cout<<endl;
//             }
            
            if (!isStable(x,y)) continue;
            // cout<<x<<" "<<y<<endl;
            ans[i] = markAndCountStable(x,y)-1;
        }
        return ans;
        
    }
    
    int markAndCountStable(int x,int y){
        if (grid[x][y]==0 || grid[x][y]== -1) return 0;
        grid[x][y]=2;
        
        int count = 1;
        
        for (pair<int,int> &dir:directions){
            int r = x+dir.first;
            int c = y+dir.second;
            
            if (r<0 || r>=m || c<0 || c>=n || 
                grid[r][c]==0 || grid[r][c] == -1 || grid[r][c]==2) 
            continue;
            // cout<<"row column "<<r<<" "<<c<<endl;
            count += markAndCountStable(r,c);
            
        }
        return count;
    }
    
    bool isStable(int x,int y){
        if (x==0)return true;
        for (pair<int,int> &dir:directions){
            int r = x+dir.first;
            int c = y+dir.second;
            
            if (r<0 || r>=m || c<0 || c>=n) 
            continue;
            if (grid[r][c]==2)return true;
            // count += markAndCountStable(r,c);
            
        }
        return false;
    }
};