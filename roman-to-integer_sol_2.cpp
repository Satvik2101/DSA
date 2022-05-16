#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        map<string,int> values ={
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900}
        };
        map<char,int> singleValues ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        for (int i =0;i<s.length();i++){
            if (i+1<s.length()){
                
                auto valueFound= values.find(s.substr(i,2));
                if (valueFound !=values.end()){
                    cout<<"HERE";
                    ans+=valueFound->second;
                    i++;
                    continue;

                }
            }
            ans+= singleValues.find(s[i])->second;
        }
        return ans;
    }
};