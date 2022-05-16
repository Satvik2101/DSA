#include <bits/stdc++.h>
// kbx2157
using namespace std;
#include <bits/stdc++.h>
// kbx2157
using namespace std;
// Question Link: https://leetcode.com/problems/next-greater-element-iii/

class Solution {
  public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string maxVal = to_string(INT_MAX);

        int len = s.length();
        int i = len - 1;

        for (; i > 0; i--) {

            if (s[i] > s[i - 1]) {
                // Check from i to end for lowest value bigger than s[i-1]
                int lowestIndex = i;
                for (int j = i; j < len; j++) {
                    if (s[j] < s[lowestIndex] && s[j] > s[i - 1]) {
                        lowestIndex = j;
                    }
                }
                swap(s[lowestIndex], s[i - 1]);
                break;
            }
        }

        // cout<<s;
        if (i == 0)
            return -1;
        sort(s.begin() + i, s.end());
        // cout<<s;
        if (len == maxVal.length() && s > maxVal)
            return -1;
        return stoi(s);
    }
};