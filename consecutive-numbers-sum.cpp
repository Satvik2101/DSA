#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;

        for (int k = 2;k<=sqrt(2*n);k++){
            int x  = (n- ((k*(k-1))/2));
            if(x!=0 && x%k==0){
                // cout<<k<<" ";
                ans++;
            }
        }
        return ans;
    }
};