#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    map<int,vector<int>> row;
    map<int,vector<int>> col;
    vector<int> visited;
    
    struct Point{
        // int id;
        int x;
        int y;
        
        bool operator == (const Point& other) const {
            return other.x == x && other.y ==y;
        }
        bool operator < (const Point& other) const {
            return other.x == x?other.y<y : other.x < x;
        }
        
        Point( int x, int y){
            // this->id = id;
            this->x = x;
            this->y = y;
        }
        Point(){
            x = -1;
            y = -1;
        }
        
    };
    map<int,Point> points;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        visited = vector<int>(n,0);

        for (int i = 0;i<n;i++){
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
            points.insert({i,Point(stones[i][0],stones[i][1])});
        }
        int count =0;
        for (int i = 0;i<n;i++){
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }
        return n-count;
        
    }
    
    void dfs(int id){
        visited[id] = 1;
        Point p = points[id];
        if (p.x == -1){
            cout<<"WTF";
            return;
        }
        for (int rowNeighbour:row[p.x]){
            if (!visited[rowNeighbour]) dfs(rowNeighbour);
        }
        for (int colNeighbour:col[p.y]){
            if (!visited[colNeighbour]) dfs(colNeighbour);
        }
    }
};