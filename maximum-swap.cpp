#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) {
 string str = to_string(num);
    int n = str.size();
    int maxIndex = n-1;
    int leftIndex = -1;
    int rightIndex = -1;

    for (int i = n - 1; i >= 0; i--) {
        if ((str[i] > str[maxIndex])) {
            maxIndex = i;
        } else if ( str[i] < str[maxIndex]) {
            leftIndex = i;
            rightIndex = maxIndex;
        }
    }
    if (leftIndex == -1)
        return num;
    swap(str[leftIndex], str[rightIndex]);
    return stoi(str);
    }
};