#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    int MAX;
    struct Point{
        int x;
        int y;
        
        bool operator == (const Point &other) const{
            return other.x == x && other.y == y;
        }
        bool operator < (const Point &other) const{
            return other.x!=x? x<other.x : y<other.y;
        }
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
    };
    // Point null = Point(-1,-1);
    map<Point,vector<Point>> adj;
    map<Point,int> visited;
    int n;
    
    int removeStones(vector<vector<int>>& stones) {
        
        // MAX = INT_MIN;
        n = stones.size();
        for (int i = 0;i<n;i++){
            Point p = Point(stones[i][0],stones[i][1]);
            visited.insert({p,0});
            for (int j = 0;j<n;j++){
                if (p.x == stones[j][0] || p.y == stones[j][1]){
                    adj[p].push_back(Point(stones[j][0],stones[j][1]));
                }   
            }
        }
        int count= 0;
        for (auto pointData:visited){
            if (!pointData.second){
                dfs(pointData.first);
                count++;
            }
        }  
        return n-count;
        
    }
    
    void dfs(Point pt){
        visited[pt] = 1;
        for (Point &neighbour : adj[pt]){
            if (!visited[neighbour])
                dfs(neighbour);
        }
    }
};