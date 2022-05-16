#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses,0);
        for (int i = 0;i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
            in[prereq[i][0]]++;
        }
        
        queue<int> q;
        int count = 0;
        for (int i = 0;i<numCourses;i++){
            if (!in[i])q.push(i);
        }
        vector<int> ans;
        while (!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for (int neighbour:adj[node]){
                in[neighbour]--;
                if (!in[neighbour]) q.push(neighbour);
            }
            count++;
        }
        if (count!=numCourses)return {};
        
        return ans;
        
    }
};