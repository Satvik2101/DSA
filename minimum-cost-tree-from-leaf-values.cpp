#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        int ans = 0;
        for (int i :arr){
            while (st.top()<=i){
                int top = st.top();
                st.pop();
                ans += top*min(st.top(),i);
            }
            st.push(i);
        }
        
        while (st.size()>2){
            int top = st.top();
            st.pop();
            ans+=top*st.top();
        }
        
        return ans;
        
    }
};