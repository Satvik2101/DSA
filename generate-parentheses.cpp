#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    //vector<string> temp;
    vector<string> finalAns;
    
    void solve(string str,int index, int rqd){
        if (index>=str.length()){
            str+= string(rqd,')');
            finalAns.push_back(str);
            return;
        }
        string ogStr = str;
        for (int i=0;i<=rqd;i++){
            string toAdd =  string(i,')');
            str.insert(index,toAdd);
            //cout<<str<<endl;
            solve(str,index+i+1,rqd-i+1);
            str = ogStr;
        }
    }
    vector<string> generateParenthesis(int n) {
        string og = string(n,'(');
        solve(og,1,1);
        return finalAns;
    }
};