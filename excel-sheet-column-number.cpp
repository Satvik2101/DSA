#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string s) {
      
            int l = s.length() - 1;
    int multiplier = 1;
    while (l--)
        multiplier *= 26;
    //cout << multiplier << endl;
    int sum = 0;
    for (char c : s)
    {
        int val = c - 64;

        sum += val * multiplier;
        multiplier /= 26;
    }
    return sum;
    }
};