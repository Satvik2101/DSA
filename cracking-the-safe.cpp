#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/cracking-the-safe

class Solution {
public:
    int n,k, total;
    unordered_set<string> visited;
    string ans;
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        total = pow(k,n);
        
        ans = string(n,'0'); 
        visited.insert(ans);
        dfs();
        return ans;
    }
    
    bool dfs(){
        if (visited.size() == total) return true;
        for (int i = 0;i<k;i++){
            ans.push_back(i+'0');
            string curr = ans.substr(ans.size()-n);
            if (visited.find(curr) == visited.end()){
                visited.insert(curr);
                if (dfs()) return true;
                visited.erase(curr);
            }
            ans.pop_back();
        }
        return false;
    }
};