#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>> nFreq;
        vector<pair<char,int>> tFreq;
        
        for (int i = 0;i<name.length();){
            int count =1;
            char ogChar = name[i];
            i++;
            while (i<name.length() && name[i]==name[i-1]){
                i++;
                count++;
            }
            
            nFreq.push_back({ogChar,count});
        }
         for (int i = 0;i<typed.length();){
            int count =1;
            char ogChar = typed[i];
             i++;
            while (i<typed.length() && typed[i]==typed[i-1]){
                i++;
                count++;
            }
            tFreq.push_back({ogChar,count});
        }
        
        if (nFreq.size()!=tFreq.size()) return false;
        
        for (int i = 0;i<nFreq.size();i++){
            if (nFreq[i].first!=tFreq[i].first) return false;
            if (nFreq[i].second>tFreq[i].second) return false;
        }
        return true;
    }
};