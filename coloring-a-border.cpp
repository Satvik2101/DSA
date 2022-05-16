#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/coloring-a-border

class Solution {
public:
    int n,m;
    set<pair<int,int>> seen;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int search = grid[row][col];
        n = grid.size();
        m = grid[0].size();
        searchGrid(grid,row,col,search,color);
        return grid;
        
    }
    
    bool searchGrid(vector<vector<int>> &grid,int i, int j,int search, int color){
        // cout<<i<<" "<<j<<endl;
        if (i<0 || i>=n || j<0 || j>=m || (seen.find({i,j}) != seen.end())) return false;
        // cout<<"passed first "<<endl;
        if (grid[i][j]!=search){
            // grid[i][j]=color;
            return true;
        }
        // cout<<"passed second"<<endl;
        seen.insert({i,j});
        if (i==0||i==n-1||j==0||j==m-1){
            // cout<<"hereeeee"<<i<<" "<<j;
            grid[i][j]=color;
        }
        
        bool val1 = searchGrid(grid,i-1,j,search,color);       
        bool val2 = searchGrid(grid,i+1,j,search,color);         
        bool val3 = searchGrid(grid,i,j-1,search,color);         
        bool val4 = searchGrid(grid,i,j+1,search,color);
        if (val1||val2||val3||val4){
           grid[i][j]=color;
        }
        return false;


    }
};