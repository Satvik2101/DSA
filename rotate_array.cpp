#include <bits/stdc++.h>
// kbx2157
using namespace std;
// Question Link: https://leetcode.com/problems/rotate-array/

// This logic is so that the solution is O(1), a trivial solution would use O(n)
// space
class Solution {
  public:
    void reversePart(vector<int> &nums, int startIndex) {
        reverse(nums.begin() + startIndex, nums.end());
    }
    void rotate(vector<int> &nums, int k) {

        int n = nums.size();
        k = k % n;
        reversePart(nums, n - k);
        reversePart(nums, 0);
        reversePart(nums, k);
    }
};
