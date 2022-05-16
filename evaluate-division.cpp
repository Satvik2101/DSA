#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> vertices;
        unordered_map<string,vector<pair<string,double>>> adjList;
        
        for (int i = 0;i<equations.size();i++){
            vertices.insert(equations[i][0]);            
            vertices.insert(equations[i][1]);
            
            adjList[equations[i][0]].push_back({equations[i][1],values[i]});
            adjList[equations[i][1]].push_back({equations[i][0],1/values[i]});

        }
        vector<double> ans;
        
        for (int i = 0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];
            
            if (vertices.find(start)==vertices.end() || vertices.find(end) == vertices.end()){
                ans.push_back(-1.0);
                continue;
            }
            
            unordered_map<string,double> distance;
            for (string vertice:vertices){
                distance[vertice]=INT_MAX;
            }
            distance[start]=1;
            set<pair<double,string>> s;
            
            s.insert({1,start});
            
            while (!s.empty()){
                pair<double,string> node = *(s.begin());
                s.erase(node);
                string vertice = node.second;
                
                for (auto neighbourPair :adjList[vertice]){
                    string nNode = neighbourPair.first;
                    double dist = neighbourPair.second;
                    
                    if (distance.at(vertice) * dist < distance.at(nNode)){
                        auto f = s.find({distance.at(nNode),nNode});
                        if (f!=s.end())s.erase(f);
                        distance.at(nNode) = distance.at(vertice)*dist;
                        s.insert({distance.at(nNode),nNode});
                    }
                }
            }
            
            if (distance.at(end) == INT_MAX){
                ans.push_back(-1);
            }else {
            ans.push_back(distance.at(end));
            }
            
        }
        return ans;
        // return {0};
        
    }
};