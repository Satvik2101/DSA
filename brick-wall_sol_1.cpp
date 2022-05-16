#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0;
        for (int len:wall[0]){
            width+=len;
        }
        int n = wall.size();
        
        unordered_map<int,int> bricksAt;
        for (const vector<int>&row:wall){
            int pos = 0;
            for (int brick:row){
                if (bricksAt.find(pos)==bricksAt.end()){
                    // cout<<pos<<endl;
                    bricksAt.insert({pos,n});
                }
                // cout<<pos<<" "<<bricksAt[pos]<<endl;
                bricksAt[pos] = bricksAt[pos]-1;
                pos+=brick;
            }
        }
        int minBricks = n;
        for (const pair<int,int> &p:bricksAt)
            if (p.first!=0 && p.first!= width)
                minBricks = min(minBricks,p.second);
        return minBricks;
    }
};