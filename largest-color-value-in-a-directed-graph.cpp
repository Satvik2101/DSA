#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> colors;
    vector<bool> visited;
    vector<vector<int>> dp; //dp[i] contains 26 values with color values for ith node
    set<int> currentStack;    

    int ans;
    int largestPathValue(string colorsString, vector<vector<int>>& edges) {
        int n = colorsString.length();
        adj = vector<vector<int>> (n);
        dp = vector<vector<int>>(n,vector<int>(26));
        for (vector<int> &edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        colors = vector<int>(n);
        for (int i = 0;i<n;i++){
            colors[i] = colorsString[i]-'a';
        }
        ans = INT_MIN;
        visited = vector<bool> (n,false);
        for (int i = 0;i<n;i++){
            if (!visited[i]) {
                if (dfs(i)) return -1;
                ans  = max(ans,*max_element(dp[i].begin(),dp[i].end()));
            }
        }
        // for (int i:count){
        //     cout<<i<<" ";
        // }
        return ans;
    }
    
    bool dfs(int i){
        // 
        currentStack.insert(i);
        visited[i] = true;
        for (int child:adj[i]){
            if (currentStack.find(child)!=currentStack.end()){
                return true;
            }
            if (!visited[child]) if (dfs(child)) return true;
            for (int j = 0;j<26;j++){
                dp[i][j]  = max(dp[i][j],dp[child][j]); 
            }
        }
        currentStack.erase(i);
        dp[i][colors[i]]++;
        return false;
    }
};