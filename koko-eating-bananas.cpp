#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    
    int ceil(int x, int y){
        if (x%y==0) return x/y;
        return x/y+1;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MIN;
        
        for (int i :piles){
            if (i<left) left = i;
            if (i>right) right =i;
        }
        
        int lo= left;
        int hi= right;
        
        while (lo<=hi){
            
            int k = (lo+hi)/2;
            int count= 0;
            
            for (int i:piles){
                count+= ceil(i,k);
            }
            
            if (count>h) lo=k+1;
            else hi=k-1;
        }
        return lo;
    }
};