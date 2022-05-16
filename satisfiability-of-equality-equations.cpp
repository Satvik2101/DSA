#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    vector<int> parent;

    int find(int i){
        if (i == parent[i]) return i;
        return parent[i]=find(parent[i]);
    }
    bool equationsPossible(vector<string>& equations) {
        parent = vector<int>(26,0);
        for (int i= 0;i<26;i++){
            parent[i]=i;
        }
        
        for (string &eq:equations){
            int i = eq[0]-'a';
            int j = eq[3]-'a';
            if (eq[1] == '='){
                //set union
                parent[find(i)] = parent[find(j)];
                // cout<<(char)(i+'a')<<" "<<(char)(j+'a')<<endl;
            }
        }
        
        // for (int i :parent){
        //     cout<<char(i+'a')<<" ";
        // }
        cout<<endl;
        for (string &eq:equations){
            int i = eq[0]-'a';
            int j = eq[3]-'a';
            if (eq[1] != '='){
                // find 
                if (find(i) ==  find(j)){
                    return false;
                }
            }
        }
        
        return true;
    }
};