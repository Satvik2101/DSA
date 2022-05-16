#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string str) {
        if (str.length()==0)return 0;
        
        stack<int> s;
        
        for (char c:str){
            if (s.empty()){
                s.push(c);
            }else{
                if (c==')' && s.top()=='('){
                    s.pop();
                }else{
                    s.push(c);
                }
            }
        }
        
        int right=0;
        int left = 0;
        while (!s.empty()){
            if (s.top()=='(')left++;
            else right++;
            s.pop();
        }
        return left+right;
    }
};