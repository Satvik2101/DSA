#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/plus-one

class Solution {
public:
   vector<int> plusOne(vector<int> &digits)
{
    if (digits[0] == 0)
    {
        digits[0] = 1;
        return digits;
    }
    int l = digits.size() - 1;
    while (digits[l] == 9 && l >= 0)
    {
        digits[l] = 0;
        if (l!=0)
            l--;
    }
    
    if (digits[0] == 0)
        digits.insert(digits.begin(), 1);
    else
        digits[l]++;
    return digits;
}
};