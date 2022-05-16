#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        int remaining[26]={0};
        int visited[26]={0}; 
        for (char c:s){
            remaining[c-'a']++;
        }
        stack<char> st;
        for (char c:s){
            int i = c-'a';
            
            remaining[i]--;
            if (visited[i]){
                continue;
            }
            
            while (!st.empty() && c<st.top() && remaining[st.top()-'a']!=0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            visited[i]=true;
            st.push(c);
        }
        string answer="";
        while (!st.empty()){
            answer+=st.top();
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};