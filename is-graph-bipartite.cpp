#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> parent (n,0);
        for (int i = 0;i<n;i++){
            parent[i]=0;
        }
        
        for (int i =0;i<n;i++){
            if (parent[i]!=0) continue;
            
            queue<int> q;
            q.push(i);
            parent[i]=1;
            
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                for (int neighbour:graph[curr]){
                    if (parent[neighbour]==0){
                        parent[neighbour]= -parent[curr];
                        q.push(neighbour);
                    }else{
                        if (parent[neighbour]!=-parent[curr]){
                            return false;
                        }
                    }
                    
                }
            }
        }
        return true;

        
        
    }
};