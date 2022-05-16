#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

class Solution {
public:
    
    int calculate(int i, int l, int r){
        return i-l-1+ r-i-1 + (i-l-1)*(r-i-1) +1;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        vector<int> leftIndices(n);
        vector<int> rightIndices(n);
        vector<int> validIndices(n,0);
        int leftMost = -1;
        for (int i= 0;i<n;i++){
            leftIndices[i] = leftMost;
            if (nums[i]>right)leftMost = i;
        }
        int rightMost = n;
        for (int i= n-1;i>=0;i--){
            rightIndices[i] = rightMost;
            if (nums[i]>right)rightMost = i;
        }
        for (int i = 0;i<n;i++){
            if (nums[i]>=left && nums[i]<=right){
                validIndices[i]=1;
            }
        }
        int ans = 0;
        for (int i = 0;i<n;i++){
            if (i>0){
                leftIndices[i]= max(leftIndices[i-1],leftIndices[i]);
            }
            if(validIndices[i]==0)continue;
            ans+=calculate(i,leftIndices[i],rightIndices[i]);
            leftIndices[i] = i;
        }
        
        // for(int i:leftIndices){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for (int i:rightIndices){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for (int i:validIndices){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};