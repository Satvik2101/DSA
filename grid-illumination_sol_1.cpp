#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/grid-illumination

class Solution {
public:
    // vector<vector<int>> grid;
    map<int,int> rowIlluminated;
    map<int,int> columnIlluminated;
    map<int,int> plusDiagIlluminated;
    map<int,int> minusDiagIlluminated;
    map<pair<int,int>,bool> isLampOn;
    int n;
    
    void turnLampOn(int i, int j){
        // if (i<0 || i>=n || j<0 ||j>=n) return;
        isLampOn[{i,j}] = true;
        rowIlluminated[i]++;
        columnIlluminated[j]++;
        plusDiagIlluminated[i+j]++;
        minusDiagIlluminated[i-j]++;
    }
    
    void reduceByOneIfPositive(map<int,int> &hashMap, int index){
        if (hashMap[index]>0){
            hashMap[index]--;
        }
    }
    
    bool isIlluminated(int i, int j){
        if (isLampOn[{i,j}]) return true;
        if (rowIlluminated[i]>0 || columnIlluminated[j]>0 || plusDiagIlluminated[i+j]>0 || minusDiagIlluminated[i-j]>0) return true;
        return false;
    }
        
    void turnLampOff(int i, int j){
        if (i<0 || i>=n || j<0 ||j>=n) return;
        if (!isLampOn[{i,j}])return;
        // cout<<i<<" "<<j;
        isLampOn[{i,j}] = false;
        reduceByOneIfPositive(rowIlluminated,i);
        reduceByOneIfPositive(columnIlluminated,j);
        reduceByOneIfPositive(plusDiagIlluminated,i+j);
        reduceByOneIfPositive(minusDiagIlluminated,i-j);
        // if (recurse){
        //     turnLampOff(i,j-1);
        //     turnLampOff(i,j+1);
        //     turnLampOff(i-1,j);
        //     turnLampOff(i+1,j);
        //     turnLampOff(i+1,j+1);
        //     turnLampOff(i-1,j-1);
        //     turnLampOff(i+1,j-1);
        //     turnLampOff(i-1,j+1);
        // }
        
    }
        vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        this->n = n;
        // grid = vector<vector<int>> (n, vector<int> (n,0));
        vector<int> ans;
        for (vector<int>&lamp: lamps){
            int i = lamp[0],j = lamp[1];
            if (!isLampOn[{i,j}])turnLampOn(i,j);
        }
        for (vector<int>& query:queries){
            int i = query[0], j=query[1];
            ans.push_back(isIlluminated(i,j));
            turnLampOff(i,j);
            turnLampOff(i,j-1);
            turnLampOff(i,j+1);
            turnLampOff(i-1,j);
            turnLampOff(i+1,j);
            turnLampOff(i+1,j+1);
            turnLampOff(i-1,j-1);
            turnLampOff(i+1,j-1);
            turnLampOff(i-1,j+1);
            
        }
        return ans;
    }
};