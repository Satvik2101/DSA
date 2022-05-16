#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> fuels;
        
        int currentFuel = startFuel;
        int currentPosition = 0;
        int ans = 0;
        stations.push_back({target,INT_MAX});
        for (vector<int> &station:stations){
            int position = station[0];

            currentFuel -= (position-currentPosition);
            currentPosition = position;
            while (!fuels.empty() && currentFuel<0){
                int maxFuel = fuels.top();
                currentFuel +=maxFuel;
                ans++;
                fuels.pop();
            }
            if (currentFuel<0)
                return -1;
            fuels.push(station[1]);
        }
        return ans;
        
    }
};