#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrams;
        
        for (string &s:strs){
            // const string &copy = customSort(s);
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
    
    string customSort(string &s) const {
    vector<int> count(26, 0);

    for (int i = 0;i<s.length();i++)
        count[s[i] - 'a']++;
    for (int i = 1; i < 26; i++) {
        count[i] = count[i - 1] + count[i];
    }
    int len = s.length();
    string output(len, '*');
    for (int i = len - 1; i >= 0; i--) {
        int pos = s[i] - 'a';
        // cout << count[pos] - 1 << " " << s[i] << " ";
        output[count[pos] - 1] = s[i];
        // cout << output << endl;
        count[pos]--;
    }
    return output;
}
};