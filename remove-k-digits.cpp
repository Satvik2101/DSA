#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k>= num.length()) return "0";
        stack<char> s;
        s.push(num[0]);
        int count = 0;
        int n = num.length();
        int i;
        for (i = 1;i<n;i++){
            while (!s.empty() && num[i]<s.top() && count<k){
                count++;
                s.pop();
            }
//             cout<<boolalpha<<!s.empty()<<" "<<num[i]<<endl;
            
//             cout<<( !s.empty() || num[i]!=0 )<<endl;
            if ((!s.empty()) || (num[i]!='0')){
                s.push(num[i]);
            }
        }
        int len = n-k;
        string ans = "";
        while (!s.empty() && count<k){
            s.pop();
            count++;
        }
        for (int j = 0;!s.empty() && j<len;j++){
           
            ans+=s.top();
            s.pop();
        }
        
        
        reverse(ans.begin(),ans.end());
        if (ans.length()==0) return "0";
        return ans;

    }
};