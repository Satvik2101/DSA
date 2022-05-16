#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        
        double left = arr[0]/arr[n-1],right = 1.0;
        
        while (left<right){
            double mid = (left+right)/2;
            double maxLessThanMid = 0;
            int maxI=0,maxJ=0,total = 0;
            
            int j = 1;
            for (int i = 0;i<n-1;i++){
                while (j<n && arr[i] >= mid*arr[j]) j++;
                
                total += (n-j);
                
                if (j==n)break;
                
                double f = ((double)arr[i])/arr[j];
                if (f>maxLessThanMid){
                    maxLessThanMid = f;
                    maxI = i;
                    maxJ = j;
                }
            }
            if (total == k) return {arr[maxI],arr[maxJ]};
            else if (total<k)left = mid;
            else right = mid;
        }
        return {};
        
    }
};