#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums =nums;
        tree = vector<int>(n+1,0);
        
        for (int i =0;i<n;i++){
            add(i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index]= val;
        add(index,diff);
    }
    
    void add(int index, int diff){
        index++;
        while (index<=n){
            tree[index]+=diff;
            index += (index&(-index));
        }
    }
    int sumRange(int left, int right) {
        return getSum(right)-getSum(left-1);
    }
    
    int getSum(int i){
        int ans = 0;
        i++;
        while (i>0){
            ans+=tree[i];
            i-= (i&(-i));
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */