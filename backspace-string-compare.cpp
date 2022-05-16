#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    
    string getFinal(string s){
        stack<char> st;
        
        for (char c:s){
            if ((c=='#')){
                if (!st.empty())
                    st.pop();
            }else{
                st.push(c);
            }
        }
        string out="";
        while (!st.empty()){
            out+=st.top();
            st.pop();
        }
        return out;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = getFinal(s);
        string s2 = getFinal(t);
        // cout<<s1<<" "<<s2<<endl;
        return s1==s2;
        
    }
};