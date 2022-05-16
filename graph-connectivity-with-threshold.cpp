#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/graph-connectivity-with-threshold

class Solution {
public:
    vector<int> parent;
    int n;
    int find(int i){
        if (parent[i]==i)return i;
        return parent[i] = find(parent[i]);
    }
    
    void merge(int i,int j){
        parent[find(i)] = parent[find(j)];
    }
    
    void assignMultiples(int x){
        for (int i = 2;x*i<=n;i++){
            merge(x,x*i);
        }
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans;
        this->n = n;
        parent = vector<int> (n+1);
        for (int i = 0;i<n+1;i++){
            parent[i]= i;
        }
        for (int i = threshold+1; i<=n/2; i++){
            assignMultiples(i);
        }
//         for (int i :parent){
//             cout<<i<<" ";
//         }
        
        for (vector<int> &query:queries){
            ans.push_back(find(query[0]) == find(query[1]));
        }
        return ans;
    }
    
    
};