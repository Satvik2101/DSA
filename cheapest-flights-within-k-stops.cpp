#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    struct flight{
        int node;
        int weight;
        int stops;
        
        flight(int n,int w,int s):node(n),weight(w),stops(s){}
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int> (n,INT_MAX));
        //dp[i][j] gives cheapest src to j with at most i stops 
        for (int i = 0;i<=k+1;i++){
            dp[i][src] = 0;
        }
        
        for (int i = 1;i<=k+1;i++){
            for (vector<int> &flight:flights){
                int start = flight[0];
                int end = flight[1];
                int cost = flight[2];
                
                if (dp[i-1][start] != INT_MAX){
                    dp[i][end] = min(dp[i][end],dp[i-1][start] + cost);
                }
            }
        }
        return (dp[k+1][dst] == INT_MAX)? -1 :dp[k+1][dst];
        
    }
};