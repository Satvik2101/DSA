#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    bool match(string &needle,string &haystack, int index){
        
        int i = 0;
        cout<<index<<endl;
        while (i<needle.length() && (i+index)<haystack.length()){
            if (needle[i]!=haystack[i+index]) return false;
            i++;
        }
        if (i==needle.length() && (i+index)<=haystack.length())
            return true;
        return false;
    }
    int strStr(string haystack, string needle) {
        if (needle.length()==0) return 0;
        if (haystack.length()==0) return -1;
        if (haystack.length()<needle.length()) return -1;
        for (int i = 0;i<haystack.length()-needle.length()+1;i++){
            if (match(needle,haystack,i)){
                return i;
            }
        }
        return -1;
    }
};