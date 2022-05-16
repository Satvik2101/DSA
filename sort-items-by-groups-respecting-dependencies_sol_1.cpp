#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> pre(m,0);
        vector<int> post(m,0);
        map<int,vector<int>> adj;
        for (int i = 0;i<m;i++){
            pre[i]= n +2*i;
            post[i] = n + 2*i +1;
        }
        map<int,int> indegree;
        set<int> nodes;
        for (int i = 0;i<n;i++){
            int group_id = group[i];
            vector<int> &beforeList = beforeItems[i];
            nodes.insert(i);
            
            if (group_id!=-1){
                adj[pre[group_id]].push_back(i);
                adj[i].push_back(post[group_id]);
                // nodes.insert(pre[group_id]);
                // nodes.insert(post[group_id]);
                indegree[i]++;
                indegree[post[group_id]]++;
            }
            
            for (int parent:beforeList){
                if (group[parent] == group_id){
                    adj[parent].push_back(i);
                    indegree[i]++;
                } else if (group[i] == -1){
                    if (group[parent]==-1){
                        adj[parent].push_back(i);
                    }else{
                        adj[post[group[parent]]].push_back(i);
                    }
                    indegree[i]++;
                }else{
                    if (group[parent] == -1){
                        adj[parent].push_back(pre[group[i]]);
                    }else{
                        adj[post[group[parent]]].push_back(pre[group[i]]);
                    }
                    indegree[pre[group[i]]]++;
                }
            }
        }
        
            queue<int> q;
            for (int i:nodes){
                if (!indegree[i])q.push(i);
            }
            for (int i:pre){
                if (!indegree[i])q.push(i);
            }
            for (int i:post){
                if (!indegree[i])q.push(i);

            }
            vector<int> ans;
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                queue<int> currQ;
                currQ.push(curr);
                vector<int> currAns;
                
                while (!currQ.empty()){
                    int node = currQ.front();
                    currQ.pop();
                    currAns.push_back(node);
                    
                    for (int i:adj[node]){
                        indegree[i]--;
                        if (indegree[i]==0) currQ.push(i);
                    }
                }
                for (int i:currAns){
                    if (i<n)
                    ans.push_back(i);
                }
                
            }
            if (ans.size()!=n)return {};
            return ans;
    }
};