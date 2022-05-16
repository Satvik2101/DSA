#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res =0;
        // if ith bit is set in n, (31-i)th bit will be set in res 
        for (int i =0; i<32;i++)
        {
            if (n&(1<<i))
                res+=1<<(31-i);
        }
        return res;
    }
};