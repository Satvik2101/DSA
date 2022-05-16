#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLength = 0;
        int maxSoFar = 0;
        map<char,int> alreadySeen;
        for (int i =0 ;i<len;i++){
            if (alreadySeen.empty() || (alreadySeen.find(s[i])==alreadySeen.end())){
                maxLength++;
                maxSoFar =max(maxSoFar,maxLength);
                alreadySeen.insert(make_pair(s[i],i));
            } else{
                maxSoFar =max(maxSoFar,maxLength);
                maxLength = 0; 
                i = alreadySeen.find(s[i])->second;
                alreadySeen.clear();
            }
        }
        return maxSoFar;
    }
};