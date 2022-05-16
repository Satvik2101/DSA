#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int res=0;
        int ans =INT_MAX;
        int finalans=0;
        int gap=0;
        
        if(nums.size()==3)
        {
            return nums[0]+nums[1]+ nums[2];
        }

        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size()-2; i++)
        {
            int lo = i+1;
            int hi = nums.size()-1;
            while(lo<hi)
            {
                if((nums[lo]+nums[hi]+ nums[i])>target)
                {
                    res = nums[lo]+nums[hi]+ nums[i];
                    hi --;
                    gap = target - res;
                    if(gap<0)
                    {
                        gap = gap*(-1);
                    }
                    if(gap<ans)
                    {
                       finalans = res;
                        ans = gap;
                    }
                }
                else if((nums[lo]+nums[hi]+ nums[i])<target)
                {
                    res = nums[lo]+nums[hi]+nums[i];
                    lo ++;
                    gap =  target-res;
                    
                    if(gap<0)
                    {
                        gap*-1;
                    }
                    if(gap<ans)
                    {
                        finalans = res;
                        ans = gap;
                    }
                }
                else
                {
                    finalans = nums[lo]+nums[hi]+ nums[i];
                    return finalans;
                }

            }
        }
        return finalans;
        
    }
};