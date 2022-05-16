#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/factorial-trailing-zeroes

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int i =5;
        while (i<=n)
        {
            sum+= n/i;
            i*=5;
        }
        return sum;
    }
};