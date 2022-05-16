#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> people;
        
        for (int i =0; i<groupSizes.size();i++){
            people.push_back(make_pair(groupSizes[i],i));
        }
        sort(people.begin(),people.end());
        
        vector<vector<int>> ans;
        int prevGroup = -1;
        int currIndex = -1;
        for (pair<int,int> p : people){
            int currGroup = p.first;
            
            if (currGroup !=prevGroup){
                ans.push_back({});
                currIndex++;
            
                prevGroup = currGroup;
            }else if (currIndex>=0 && ans[currIndex].size()>= currGroup){
                ans.push_back({});
                currIndex++;
            }
            
            ans[currIndex].push_back(p.second);
        }
        return ans;
    }
};