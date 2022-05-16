#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    vector<int> weights;
    int days;
    int shipWithinDays(vector<int> const &w, int d) {
        weights = w;
        days = d;
        int maxWeight = 0;
        int sum= 0;
        for (int i :weights){
            if (i>maxWeight) maxWeight = i;
            sum+=i;
        }
        
        int lo = maxWeight;
        int hi = sum;
        int mid;
        int ans;
        while (lo<=hi){
            
            mid = (lo+hi)/2;
            bool isPossible = possible(mid);
            // cout<<isPossible<<" "<<mid<<endl;
            if (isPossible){ 
            hi = mid-1;
            ans = mid;               
            }
            else lo = mid+1;
        }
        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
        return ans;
        
    }
    
    bool possible(int capacity){
        int count = 0;
        int sum =0;
        for (int i:weights){
            if (sum+i>capacity){
                count++;
                sum = i;
            }else{
                sum+=i;
            }
            
            if (count>days) return false;
        }
         if (sum != 0)
            count++;
        if (count > days)
            return false;
        return true;
    }
};