#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c:s){
         if (c=='(' || c=='{' || c=='['){
             //cout<<"pushing "<<c<<endl;
             st.push(c);
         }else{
             if (st.empty()){
                 //cout<<'1';
                 return false;
             }
             if (st.top()=='(' && c==')'){
                //cout<<"21\n";
                st.pop();
             }else if (st.top()=='[' && c==']'){
                //cout<<"22\n";
                st.pop();
             }else if (st.top()=='{' && c=='}'){
                //cout<<"23\n";
                st.pop();
             }else{
                 //cout<<c<<" false";
                 return false;
             }
         }   
        }
        //cout<<'3';
        return st.empty();
    }
};