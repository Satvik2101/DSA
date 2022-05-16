#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count;
        for (char c:t)count[c]++;
        
        int start = 0;
        int end = 0;
        int toFind = t.size();
        int ansStart = -1;
        int ansLen = INT_MAX;
        
        while (end<s.size()){
            if (count[s[end]]>0) toFind--;
            count[s[end]]--;
            
            end++;
            
            while (toFind == 0){
                if (end-start < ansLen){
                    ansLen = end-start;
                    ansStart = start;
                }
                count[s[start]]++;
                if (count[s[start]]>0) toFind++;
                start++;
            }
        }
        if (ansLen == INT_MAX)return "";
        return s.substr(ansStart,ansLen);
    }
    
//         unordered_map<char, int> count;
//     for (auto c : t) count[c]++;
//     int start = 0, end = 0, toFind = t.size(), minStart = -1, minLen = INT_MAX;
//     while (end < s.size()) {

//         if (count[s[end]] > 0)
//             toFind--;

//         count[s[end]]--;
//         end++;

//         while (toFind == 0) {
//             if (end - start < minLen) {
//                 minStart = start;
//                 minLen = end - start;
//             }
//             count[s[start]]++;
    
//             if (count[s[start]] > 0)
//                 toFind++;
//             start++;
//         }
//     }
//     if (minLen != INT_MAX)
//         return s.substr(minStart, minLen);
//     return "";
//     }
};