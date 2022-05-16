#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if (i == parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        parent = vector<int> (n);
        for (int i = 0;i<n;i++){
            parent[i]=i;
        }
        vector<int> ans={-1,-1};
        for (vector<int> &edge: edges){
            int start = edge[0]-1;
            int end = edge[1]-1;
            int sRep = find(start);
            int eRep = find(end);
            if (sRep == eRep){
                ans = edge;
            }
            parent[sRep] = parent[eRep];
        }
        
        return ans;
    }
};