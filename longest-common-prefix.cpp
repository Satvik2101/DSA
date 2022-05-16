#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        int i = 0;
        char curChar = strs[0][0];
        
        while (true){
            for (string str:strs){
                if (str.length()==0){
                    return "";
                }
                if (i>str.length()){
                    return ans;
                }
                if (str[i]!=curChar){
                    return ans;
                }
            }
            ans+=curChar;
            int len = strs[0].length();
            if (len>i+1){
                
                curChar = strs[0][++i];
                //cout<<curChar;
            }
            else return ans;
        }
    }
};