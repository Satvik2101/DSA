#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    
    vector<int> merge(vector<int> v1, vector<int> v2, int totalLen){
        vector<int> ans(totalLen);
        
        int i=0,j=0;
        int curr = 0;
        int len1 = v1.size();
        int len2 = v2.size();
        
        while (i<len1 && j<len2){
            if (v1[i]<v2[j]){
                ans[curr]=v1[i];
                i++;
            }else{
                ans[curr]=v2[j];
                j++;
            }
            curr++;
        }
        
        while (i<len1){
            ans[curr++]=v1[i++];
        }
        while (j<len2){
            ans[curr++]=v2[j++];
        }
        return ans;
    }
    void printVector(vector<int> v){
        for (int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int firstPositivePosition;
        int len = nums.size();
        for (int i = 0;i<len;i++){
            if (nums[i]>=0){
                firstPositivePosition = i;
                break;
            }
        }
        vector<int> neg (nums.begin(),nums.begin()+firstPositivePosition);
        vector<int> pos (nums.begin()+firstPositivePosition,nums.end());
        // printVector(neg);
        // printVector(pos);
        reverse(neg.begin(),neg.end());
        for (int i = 0;i<neg.size();i++){
            neg[i] = -neg[i];
        }
        //Merge
        vector<int> merged = merge(neg,pos,len);
        for (int i = 0;i<len;i++){
            merged[i]= merged[i]*merged[i];
        }
        return merged;
    }
    
    
};