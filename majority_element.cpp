#include <bits/stdc++.h>
// kbx2157
using namespace std;
#include <bits/stdc++.h>
// kbx2157
using namespace std;
// Question Link: https://leetcode.com/problems/majority-element/submissions/

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int curr = nums[0];
        int count = 0;

        for (int i : nums) {
            if (i == curr) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                curr = i;
                count++;
            }
        }
        return curr;
    }
};