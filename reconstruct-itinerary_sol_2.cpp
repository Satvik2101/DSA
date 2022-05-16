#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    map<string,multiset<string>> routes;
    vector<string> finalRoute;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> & ticket:tickets){
            routes[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(finalRoute.begin(),finalRoute.end());
        return finalRoute;
    }
    
    void dfs(string node){
     
        
        while (!routes[node].empty()){
            string neighbour = *routes[node].begin();
            routes[node].erase(routes[node].begin());
            dfs(neighbour);
        }
        
        finalRoute.push_back(node);
    }
    
};