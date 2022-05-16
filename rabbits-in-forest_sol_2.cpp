#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int ceil(int x, int y){
        if ((x/y)*y == x) {
            return x/y;
        }
        return x/y+1;
    }
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int,int> count;
        for (int i:answers){
            count[i]++;
        }
        
        for (const pair<int,int> &p: count){
            int value = p.first;
            int rabbitsAnswering = p.second;
            
            ans += ceil(rabbitsAnswering,value+1)*(value+1);
        }
        return ans;
        
    }
};