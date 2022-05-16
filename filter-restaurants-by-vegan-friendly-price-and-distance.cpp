#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance

class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        if (a[1]!=b[1]){
            return a[1]>b[1];
        }
        else return a[0]>b[0];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
     vector<vector<int>> allowedRestaurants;
        for (vector<int> v:restaurants){
            if (v[3]<=maxPrice && v[4]<=maxDistance){
                if (!veganFriendly){
                    allowedRestaurants.push_back(v);
                }else{
                    if (v[2]){
                    allowedRestaurants.push_back(v);
                    }
                }
            }
        }
        sort(allowedRestaurants.begin(),allowedRestaurants.end(),compare);
        vector<int> ans;
        for (vector<int> v:allowedRestaurants){
            ans.push_back(v[0]);
        }
        return ans;   
    }
};