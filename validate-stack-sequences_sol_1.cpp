#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pop = 0;
        
        int n = pushed.size();
        
        for (int i:pushed){
            s.push(i);
            
            while (!s.empty() && pop<n && (s.top() == popped[pop])){
                s.pop();
                pop++;
            } 
        }
        return pop==n;
    }
};