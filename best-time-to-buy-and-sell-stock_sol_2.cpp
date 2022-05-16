#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int minPrice = INT_MAX;
        
        for (int val:prices){
            if (val<minPrice) minPrice = val;
          
            maxProfit = max(maxProfit,val-minPrice);
        }
        return maxProfit;
    }
};