#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class makeDSU{
private:
	vector <int> parent;
	vector <int> rank;

public:

	makeDSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1);
		for(int i = 0; i<= n ; i++){
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int findPar(int node){
		if(node == parent[node]) return node;

		return parent[node] = findPar(parent[node]);
	}

	void unionDSU(int u, int v){
		u = findPar(u);
		v = findPar(v);

		if(rank[u] < rank[v]){
			parent[u] = v;
		}
		else if(rank[v] < rank[u]){
			parent[v] = u;
		}
		else {
			parent[v] = u;
			rank[u]++;
		}
	}

};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        unordered_map <int, vector <int>> row, col;
        
        for(int i = 0; i < n; i++){
            auto stone = stones[i];
            row[stone[0]].push_back(i);
            col[stone[1]].push_back(i);
        }
        
        makeDSU d(n);
        
        for(int i = 0; i < n; i++){
            auto stone = stones[i];
            for(auto it: row[stone[0]]) d.unionDSU(i, it);
            for(auto it: col[stone[1]]) d.unionDSU(i, it);
        }
        
        unordered_set<int> parents;
        
        for(int i = 0; i < n; i++){
            parents.insert(d.findPar(i));
        }
        
        return n - parents.size();
        
    }
};