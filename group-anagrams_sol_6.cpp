#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        
        for (string s:strs){
            string copy = s;
            sort(copy.begin(),copy.end());
            anagrams[copy].push_back(s); 
        }
        vector<vector<string>> ans;
        // ans.reserve(anagrams.size());
        for (auto it = anagrams.begin();it!=anagrams.end();it++){
            ans.push_back(move(it->second));   
        }
        return ans;
        
    }
};