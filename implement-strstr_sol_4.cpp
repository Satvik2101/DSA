#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    
    int needleLength;
    int haystackLength;
    bool match(string &needle,string &haystack, int index){
        
        int i = 0;
        cout<<index<<endl;
        while (i<needleLength && (i+index)<haystackLength){
            if (needle[i]!=haystack[i+index]) return false;
            i++;
        }
        if (i==needleLength && (i+index)<=haystackLength)
            return true;
        return false;
    }
    int strStr(string haystack, string needle) {
        
       int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};