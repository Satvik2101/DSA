#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        int dict[26]={0};
        for (char c:s){
            dict[c-'a']++;
        }
        string ans = "";
        
        for (char c:order){
            while (dict[c-'a']>0){
                ans+=c;
                dict[c-'a']--;
            }
        }
        //cout<<ans;
        for (int i=0;i<26;i++){
            while (dict[i]>0){
                ans+= ('a'+i);
                //cout<<ans<<" "<<dict[i];
                dict[i]--;
            }
        }
        return ans;
    }
};