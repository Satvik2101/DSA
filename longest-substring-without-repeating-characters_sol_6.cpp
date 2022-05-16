#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLength = 0;
        unordered_set<char> alreadySeen;
        int start = 0;
        int end = 0;
        while (end<len){
            if (alreadySeen.find(s[end])!=alreadySeen.end()){
                while (s[start]!=s[end]){
                    alreadySeen.erase(s[start]);
                    start++;
                }
                //alreadySeen.erase(s[start]);
                start++;
                end++;
                continue;
            }
            if (end-start+1>maxLength){
                maxLength = end-start+1;
            }
            alreadySeen.insert(s[end]);
            end++;
        }
     return maxLength;   
    }
};