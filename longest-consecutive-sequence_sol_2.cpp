#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    unordered_map<int,int> parent;
    
    void merge(int x, int y){
        parent[(find(x))]  = find(y);
    }
    int find(int i){
        if (i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    
    static bool comp(pair<int,int> p1, pair<int,int> p2){
        return p1.second<p2.second;
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int,int> count;
        for (int num:nums){
            count[num]++;
        }

        for (int num:nums){
            parent[num] =num;
        }
        
        for (const pair<int,int> &p:count){
            int number = p.first;
            // int numberCount = p.second;
            
            if (count.find(number-1)!=count.end()){
                merge(number-1,number);
            }
            if (count.find(number+1)!=count.end()){
                merge(number,number+1);
            }
        }
        unordered_map<int,int> parentCount;
        for (const pair<int,int> &p: parent){
            // cout<<p.first<<" "<<p.second<<endl;
            parentCount[find(p.second)]++;
        }
        return (*max_element(parentCount.begin(),parentCount.end(),comp)).second;
    }
};