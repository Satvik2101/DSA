#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    bool inc;
    bool bought = false;
    int buyingPrice, sum = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (i + 1 < prices.size())
            inc = prices[i + 1] > prices[i];
        else if (i == prices.size() - 1 && bought)
        {
            sum += prices[i] - buyingPrice;
            break;
        }
        if (inc && !bought)
        {
            bought = true;
            buyingPrice = prices[i];
        }
        if (inc && bought)
            continue;
        if (!inc && bought)
        {
            bought = false;
            sum += prices[i] - buyingPrice;
        }
    }
    return sum;
}
};