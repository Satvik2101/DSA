#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    int m;
    int n;
    inline int v_id(int i, int j){
        return m*i+j;
    }
    unordered_set<int> visited;
    
    inline bool seen(int node){
        return visited.find(node)!=visited.end();
    }
    int numIslands(vector<vector<char>>& grid) {
        int V = 0;
        n = grid.size();
        m= grid[0].size();
        // cout<<m<<" "<<n<<endl;
        //vertice_id(grid[i][j]) = n*i +j
        
        unordered_map<int,vector<int>> adj;
        // vector<int> outsideNeighbours;
        // int outside = n*m;
        for (int i = 0;i<n;i++){
            for (int j = 0;j<m;j++){
                if (grid[i][j]=='0')continue;
                // int v_id = n*i+j;
                V++;
                vector<int> neighbours;
                
                if (i>0 && grid[i-1][j]=='1'){
                    neighbours.push_back(v_id(i-1,j));
                }
                if (i<n-1 && grid[i+1][j]=='1'){
                    neighbours.push_back(v_id(i+1,j));
                }
                if (j>0 && grid[i][j-1]=='1'){
                    neighbours.push_back(v_id(i,j-1));
                }
                if (j<m-1 && grid[i][j+1]=='1'){
                    neighbours.push_back(v_id(i,j+1));
                }
                // if (i==0 || j==0 ||i==n-1||j==m-1){
                //     neighbours.push_back(outside);
                //     // outsideNeighbours.push_back(v_id(i,j));
                // }
                adj.insert({v_id(i,j),neighbours});
            }
        }
        
        int ans = 0;
        
        for (auto p:adj){
            if (!seen(p.first)){
                dfs(adj,p.first);
                ans++;
            }
        }
        return ans;
        
        
    }
    
    void dfs(unordered_map<int,vector<int>> &adj, int node){
        visited.insert(node);
        // cout<<node<<endl;
        for (int i:adj[node]){
            if (!seen(i)){
                dfs(adj,i);
            }
        }
    }
};