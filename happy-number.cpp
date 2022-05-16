#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
        return true;
    int og = n;
    vector<int> sums = {};
    int sum = 0;
    while (sum != 1)
    {
        sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        //cout << sum << endl;
        if (find(sums.begin(), sums.end(), sum) != sums.end())
            break;
        sums.push_back(sum);
        n = sum;
    }
    if (sum == 1)
        return true;
    else
        return false;

        
    }
};