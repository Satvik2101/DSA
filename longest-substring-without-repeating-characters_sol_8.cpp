#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> positions (256,-1);
        int start = -1;
        int maxLength =0;
        for (int i=0;i<s.length();i++){
            if (positions[s[i]]>start){
                start = positions[s[i]];
            }
            positions[s[i]]=i;
            maxLength = max(maxLength,i-start);
        }
     return maxLength;   
    }
};