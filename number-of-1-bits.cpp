#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i=0;
        while (i<32)
        {   if (n&(1<<i))
                count++;
            i++;
        }
        return count;
    }
};