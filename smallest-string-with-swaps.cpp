#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/smallest-string-with-swaps

class Solution {
public:
    vector<int> parent;
    
    int find(int i){
        if (i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    
    void merge(int i,int j){
        parent[find(i)] = parent[find(j)];
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //Find components, sort the letters within each component
        // Return final string
        
        int n = s.length();
        
        parent = vector<int> (n);
        
        for (int i = 0;i<n;i++){
            parent[i]=i;
        }
        
        for (vector<int> &pair:pairs){
            merge(pair[0],pair[1]);
        }
        
        unordered_map<int,vector<int>> children;
        unordered_map<int,vector<char>> characters;
        for (int i=0;i<n;i++){
            children[find(i)].push_back(i);
            characters[find(i)].push_back(s[i]);
        }
        
        for (int i = 0;i<n;i++){
            if (parent[i]!=i)continue;
            
            sort(characters[i].begin(),characters[i].end());
        }
        
        for (int i = 0;i<n;i++){
            if (parent[i]!=i)continue;
            
            for (int j = 0;j<children[i].size();j++){
                s[children[i][j]] = characters[i][j];
            }
        }
        return s;
        
    }
};