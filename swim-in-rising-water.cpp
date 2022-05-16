#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/swim-in-rising-water


class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,pair<int,int>> Data; //time,x,y
    Data make(int t, int x,int y){
        return {t,{x,y}};
    }
    unordered_map<int,bool> seen;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<Data,vector<Data>,greater<Data>> pq;
        
        pq.push(make(grid[0][0],0,0));
        seen[grid[0][0]] = true;
        
        int ans = 0;
        while (!pq.empty()){
            Data d = pq.top();
            pq.pop();
            ans = max(d.first,ans);
            
            if (d.second.first == n-1 && d.second.second == n-1){
                return ans;
            }
            
            for (pair<int,int> &p :dir){
                int x = d.second.first+p.first;
                int y = d.second.second+p.second;
                if (x<0 || x>=n ||y<0 ||y>=n ) continue;
                if (seen[grid[x][y]])continue;
                seen[grid[x][y]]= true;
                pq.push(make(grid[x][y],x,y));
            }
        }
        return ans;
        
    }
};