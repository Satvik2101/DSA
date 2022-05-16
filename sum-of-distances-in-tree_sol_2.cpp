#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/sum-of-distances-in-tree

class Solution {
public:
    vector<unordered_set<int>> adj;
    vector<int> ans;
    vector<int> count;
    int n;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj = vector<unordered_set<int>>(n);
        ans = vector<int>(n);
        count = vector<int>(n,1);
        
        for (vector<int> &edge:edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return ans;
        
    }
    
    void dfs(int node, int parent){
        for (int nodeChild:adj[node]){
            if (nodeChild == parent) continue;
            dfs(nodeChild,node);
            count[node] += count[nodeChild];
            ans[node] += ans[nodeChild] + count[nodeChild];
        }
    }
    
    void dfs2(int node, int parent){
        for (int nodeChild:adj[node]){
            if (nodeChild== parent)continue;
            ans[nodeChild] = ans[node] - count[nodeChild] + n-count[nodeChild];
            dfs2(nodeChild,node);
        }
    }
};