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
        
        needleLength = needle.length();
        haystackLength = haystack.length();
        if (needleLength==0) return 0;
        if (haystackLength==0) return -1;
        if (haystackLength<needleLength) return -1;
        for (int i = 0;i<haystackLength-needleLength+1;i++){
            if (match(needle,haystack,i)){
                return i;
            }
        }
        return -1;
    }
};