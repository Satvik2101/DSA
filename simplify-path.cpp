#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/simplify-path

class Solution {
public:
    vector<string> split(string path){
        vector<string> ans;
        path+="/";
        string curr = "";
        for (int i=0;i<path.length();i++){
            if (path[i]=='/'){
                if (curr.length()!=0)
                    ans.push_back(curr);
                curr="";
            }else{
                curr+=path[i];
            }
        }

        return ans;
    }
    string simplifyPath(string path) {
        //string ans;
        vector<string> vals = split(path);
        string ans ="";
        stack<string> newVals;
        for (int i =0;i<vals.size();i++){
            if (vals[i]==".") continue;
            if (vals[i]==".."){
                int cnt = 1;
                while (!newVals.empty() && cnt--){
                    newVals.pop();
                }
                continue;
            }
            newVals.push(vals[i]);
        }
        while (!newVals.empty()){
            string val = newVals.top();
            
            ans= "/"+val +ans;
            newVals.pop();
        }
        if (ans.length()==0)ans+='/';
        return ans;
    }
};