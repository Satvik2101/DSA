#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1,right = 0;
        int len = s.length();
        
        int ans = 0;
        
        vector<int> positions (256,-1) ;
       
        for (int i = 0;i<len;i++){
            if (positions[s[i]]>start){
                start = positions[s[i]];
            }
            positions[s[i]] = i;
            ans = max(ans,i-start);
        }
        return ans;
    }
};