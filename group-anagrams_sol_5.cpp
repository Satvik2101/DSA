#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> anagrams;
        
        for (string s:strs){
            vector<int> letters (26,0) ;
            for (char c:s){
                letters[c-'a']++;
            }
            anagrams[letters].push_back(s); 
        }
        vector<vector<string>> ans;
        // ans.reserve(anagrams.size());
        for (auto it = anagrams.begin();it!=anagrams.end();it++){
            ans.push_back(move(it->second));   
        }
        return ans;
        
    }
};