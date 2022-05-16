#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    vector<vector<int>> adj;
    int n;
    vector<int> safe; // 1 means safe, 0 means yet to be determined, -1 means unsafe.
    set<int> inStack;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj = graph;
        n = graph.size();
        safe = vector<int> (n,0);
        
        for (int i = 0;i<n;i++){
            if (adj[i].empty()) safe[i]=1;
        }
        vector<int> ans;
        for (int i = 0;i<n;i++){
            if (safe[i]==0)dfs(i);
        }
        
        for (int i= 0;i<n;i++){
            if (safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
    
    // return true if safe
    bool dfs(int node){
        // if already determined
        if (safe[node]!=0) return (safe[node]==1);
        inStack.insert(node);
        bool isThisSafe = true;
        for (int child:adj[node]){
            if (inStack.find(child)!=inStack.end()){
                safe[child] = safe[node] = -1;
                
                isThisSafe = false;
                break;
            }
            if (!dfs(child)){
                isThisSafe = false;
                break;
            }
        }
        inStack.erase(node);
        safe[node] = isThisSafe?1:-1;
        return isThisSafe;
        
    }
};