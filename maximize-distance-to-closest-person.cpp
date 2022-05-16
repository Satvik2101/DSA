#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/maximize-distance-to-closest-person

class Solution {
public:
    
    int ceilBy2(int x){
        if (x&1){
            return x/2 +1;
        }
        return x/2;
    }
    int maxDistToClosest(vector<int>& seats) {
        int maxDist=0;
        vector<int> seatsIndices;
        for (int i = 0;i<seats.size();i++){
            if (seats[i]){
                seatsIndices.push_back(i);
            }
        }
        maxDist = seatsIndices[0];
        for (int i = 1;i<seatsIndices.size();i++){
            int val =(seatsIndices[i]-seatsIndices[i-1])/2;
            maxDist = max(val,maxDist);
        }
        int val = seats.size()- seatsIndices[seatsIndices.size()-1]-1;
        maxDist = max(maxDist, val);
        return maxDist;
        
    }
};