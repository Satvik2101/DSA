#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1=INT_MAX;
        int min2=INT_MAX;
        int max1=INT_MIN;
        int max2=INT_MIN;
        int max3=INT_MIN;
        
        for (int i:nums){
            if (i<min1){
                min2 = min1;
                min1 = i;
            }else if (i>=min1 && i<min2){
                min2 = i;
            }
            if (i>max1){
                max3= max2;
                max2 = max1;
                max1=i;
            }else if (i<=max1 && i>max2){
                max3 = max2;
                max2 = i;
            }else if (i<=max2 && i>max3){
                max3 = i;
            }
            // cout<<"max1 "<<max1<<endl;
            // cout<<"max2 "<<max2<<endl;
            // cout<<"max3 "<<max3<<endl;
            // cout<<"min1 "<<min1<<endl;
            // cout<<"min2 "<<min2<<endl;
            // cout<<"------------------"<<endl;

        }
        int ans1 = min1*min2*max1;
        int ans2 = max1*max2*max3;
        return max(ans1,ans2);
    }
};