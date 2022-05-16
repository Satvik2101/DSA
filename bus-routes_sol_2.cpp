#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/bus-routes

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> busesTillStop;
        for (int i = 0;i<routes.size();i++){
            for (int j:routes[i]){
                busesTillStop[j].push_back(i);
            }
        }
        
        queue<pair<int,int>> bfs; //stop,bus
        
        unordered_set<int> seen={source};
        
        bfs.push({source,0});
        while (!bfs.empty()){
            int stop = bfs.front().first;
            int  bus = bfs.front().second;
            bfs.pop();
            if (stop == target)return bus;
            for (int i:busesTillStop[stop]){
                for (int j:routes[i]){
                    if (seen.find(j) ==  seen.end()){
                        seen.insert(j);
                        bfs.push({j,bus+1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
        
    }

};
