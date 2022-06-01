#include <bits/stdc++.h>
// kbx2157
using namespace std;
// Question Link: https://leetcode.com/problems/remove-invalid-parentheses
class Solution {
  public:
    vector<string> ans;
    string s;
    vector<string> removeInvalidParentheses(string s) {
        this->s = s;
        int left = 0;
        int right = 0;
        for (char c : s) {
            if (c == '(')
                left++;
            if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        string curr;
        helper(curr, 0, left, right, 0);
        return ans;
    }

    void helper(string &curr, int index, int left, int right, int stack) {
        if (index == s.length()) {
            if (stack == 0 && left == 0 && right == 0)
                ans.push_back(curr);
            return;
        }

        if (s[index] == '(') {
            // skip this bracket
            if (curr.back() != '(' && left > 0) {
                helper(curr, index + 1, left - 1, right, stack);
            }
            // include this bracket
            helper(curr += '(', index + 1, left, right, stack + 1);
            curr.pop_back();

        } else if (s[index] == ')') {
            // skip this bracket
            if (curr.back() != ')' && right > 0) {
                helper(curr, index + 1, left, right - 1, stack);
            }
            // we will keep this bracket only if there is a corresponding left
            // bracket that needs a closing
            if (stack > 0) {
                helper(curr += ')', index + 1, left, right, stack - 1);
                curr.pop_back();
            }
        } else {
            // any other character, keep it and move on
            helper(curr += s[index], index + 1, left, right, stack);
            curr.pop_back();
        }
    }
};