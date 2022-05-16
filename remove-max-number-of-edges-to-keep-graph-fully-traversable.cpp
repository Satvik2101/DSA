#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable

class Solution {
public:
    
    static bool comp(vector<int> &a, vector<int>  &b) {
        return a[0]>b[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int edgeCount = 0;
        
        vector<int> aliceP(n);
        vector<int> bobP(n);
        
        int bobComponents = n;
        int aliceComponents = n;
        for (int i = 0;i<n;i++){
            aliceP[i]=bobP[i]=i;
        }
        
        sort(edges.begin(),edges.end(),comp);
        for (vector<int> &edge:edges){
            int type = edge[0], start = edge[1]-1, end = edge[2]-1;
            
            if (type==3){
                bool bob = merge(bobP,start,end);
                bool alice = merge(aliceP,start,end);
                if (bob) bobComponents--;
                if (alice) aliceComponents--;
                if (bob | alice) edgeCount++;
            }else if (type==2){
                if (merge(bobP,start,end)){
                    cout<<start<<" "<<end<<" bob";
                    edgeCount++;
                    bobComponents--;
                }
            }else{
                if (merge(aliceP,start,end)){
                    edgeCount++;
                    aliceComponents--;
                }
            }
        }
        if (bobComponents == 1 && aliceComponents ==1){
            return edges.size()-edgeCount;
        }
        // cout<<bobComponents<<" "<<aliceComponents;
        return -1;
        
    }
    int find(vector<int> &parent, int i){
        if (i == parent[i]) return i;
        return parent[i] = find(parent,parent[i]);
    }    
    
    bool merge(vector<int> &parent, int i ,int j){
        if (find(parent,i) == find(parent,j)) return false;
        
        parent[find(parent,i)] = j;
        return true;
    }
};