#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currentReverseIndex = nums.size() - 1;
    int swappedElements = 0;
    for (int i = 0; i < nums.size() - swappedElements; i++)
    {
        if (i >= currentReverseIndex)
            break;
        if (nums[i] == val)
        {
            while (nums[currentReverseIndex] == val)
            {
                currentReverseIndex--;
                if (i >= currentReverseIndex)
                    break;
            }
            swap(nums[i], nums[currentReverseIndex--]);
            swappedElements++;
        }
    }
        int ans =0;
 for (int i : nums)
    {
        if (i != val)
        {
            ans++;
        }
        else
            break;
    }
    return ans;    }
};