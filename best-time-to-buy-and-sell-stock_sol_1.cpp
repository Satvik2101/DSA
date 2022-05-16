#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int minPrice= INT_MAX;
      for (int i :prices)
      {
          if (i<minPrice)
              minPrice = i;
          if (i-minPrice>maxP)
              maxP=i-minPrice;
      }
      return maxP;
    }
};