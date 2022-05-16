#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/redundant-connection-ii

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if (i == parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         int n = edges.size();
        vector<int> candA;
        vector<int> candB;
        parent = vector<int> (n,-1);
        
        // find node with 2 parents
        for (vector<int> &edge :edges){
            if (parent[edge[1]-1] == -1) parent[edge[1]-1] = edge[0]-1;
            else{
                candA = {parent[edge[1]-1]+1,edge[1]};
                candB = edge;
                edge[1] = -1;
            }
        }
        for (int i = 0;i<n;i++){
            parent[i]=i;
        }
        // vector<int> ans={-1,-1};
        for (vector<int> &edge: edges){
            if (edge[1] == -1) continue;
            int start = edge[0]-1;
            int end = edge[1]-1;
            int sRep = find(start);
            int eRep = end;
            if (sRep == eRep){
                if (candA.empty()) return edge;
                return candA;
            }
            parent[eRep] = parent[sRep];
        }
        
        return candB;
    }
};