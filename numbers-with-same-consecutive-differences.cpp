#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
public:
    vector<int> ans;
    int n;
    int k;
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n;
        this->k= k;
        
        for (int i = 1;i<=9;i++){
            if (i+k>9 && i-k<0){
                continue;
            }
            int num = i;
            solve(num,1,i);
        }
        return ans;
    }
    void solve(int num ,int len, int prev){
        if (len==n){
            ans.push_back(num);
            return;
        }
        int op1 = prev+k;
        int op2 = prev-k;
        
        if (op1<10){
            int numCopy = num*10 + op1;
            solve(numCopy,len+1,op1);
        }
        if (op2>=0 && op1!=op2){
            int numCopy = num*10 +op2;
            solve(numCopy,len+1,op2);
        }
    }
};