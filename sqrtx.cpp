#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        int ans =1;
        while (ans<=x/ans)
        {
            ans++;
        }
        ans--;
        return ans;
    }
};