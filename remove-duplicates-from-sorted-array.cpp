#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
int removeDuplicates(vector<int> &nums)
{
    if (nums.size()==0)return 0;
    
    int x = 0;
    vector<int>::iterator it;
    for (int i = 0; i < nums.size() - 1; i++)
    {   
        int el = nums[i];
        while (nums[i + 1] == nums[i])
        {
            nums.erase(nums.begin() + i+1);
            if (i+1>=nums.size())break;
        }
    }

    return nums.size();
}

};