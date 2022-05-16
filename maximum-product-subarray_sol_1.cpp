#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> preProducts(n+1);
        preProducts[0]=1;
        for (int i = 0;i<n;i++){
            if (preProducts[i]==0){
                preProducts[i+1]=nums[i];
            }else{
                preProducts[i+1]=preProducts[i]*nums[i];                
            }
        }
        
        int numericalMax = INT_MIN;
        int actualMax = INT_MIN;
        int numericalMaxIndex;
        for (int i=1;i<=n;i++){
            actualMax= max(actualMax,preProducts[i]);
            
            if (abs(preProducts[i])>=numericalMax){
                numericalMax = abs(preProducts[i]);
                numericalMaxIndex= i;
            }            
        }
        
        if (actualMax == numericalMax) return actualMax;
        int firstNegProd = 0;
        
        int lastZeroBeforeNumMax = 0;
        for (int i = numericalMaxIndex-1;i>=0;i--){
            if (preProducts[i]==0) {
                lastZeroBeforeNumMax=i;
                break;
            }
        }
        for (int i=lastZeroBeforeNumMax+1;i<numericalMaxIndex;i++){
            if (preProducts[i]<0){
                firstNegProd = preProducts[i];
                break;
            }
        }
        int altAns=INT_MIN;
        if (lastZeroBeforeNumMax!=0){
            vector<int> beforeZeroVector (nums.begin(),nums.begin()+lastZeroBeforeNumMax-1);
             altAns = maxProduct(beforeZeroVector);
        }
        // cout<<firstNegProd<<" "<<numericalMax<<" "<<lastZeroBeforeNumMax<<" "<<numericalMaxIndex<<" "<<actualMax;
        if (firstNegProd==0) return max(actualMax,altAns);
        int betweenProd = -numericalMax/firstNegProd;
        return max(betweenProd,max(actualMax,altAns));
        
    }
};