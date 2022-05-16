#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/3sum

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int len = nums.size();
        int i = 0;
        int j = 1;
        int k = len - 1;
        while (i < len - 2) {
            if (nums[j] + nums[k] == -nums[i]) {
                ans.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (nums[j] + nums[k] < -nums[i]) {
                j++;
            } else
                k--;

            if (j >= k) {
                i++;
                j = i + 1;
                k = len - 1;
            }
        }
        vector<vector<int>> finalAns;
        for (vector<int> v : ans) {
            finalAns.push_back(v);
        }
        return finalAns;
    }
};