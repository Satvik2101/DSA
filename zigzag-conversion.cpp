#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
         string finalAnswer = "";
        
    if (numRows==1||numRows>=s.length()){
        return s;
    }
    int i = 0;
    int adder = (numRows - 1) * 2;
    int rowCount = 1;
    // Top Row;
    while (i < s.length()) {
        finalAnswer += s[i];
        i += adder;
    }
    // Middle Rows;
    i = 1;
    bool isFirstSeries = true;
    while (rowCount < numRows - 1) {
        finalAnswer += s[i];
        if (isFirstSeries) {
            adder = (numRows - 1 - rowCount) * 2;
        } else {
            adder = 2 * rowCount;
        }
        i += adder;
        if (i >= s.length()) {
            i = ++rowCount;
            isFirstSeries = true;
            continue;
        }
        isFirstSeries = !isFirstSeries;
    }
    adder = (numRows - 1) * 2;
    rowCount = numRows - 1;
    // Bottom Row;
    while (i < s.length()) {
        finalAnswer += s[i];
        i += adder;
    }
    return finalAnswer;
    }
};