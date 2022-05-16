#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> count;
        // unordered_map<int,int> doubleCount;
        
        for (int i:arr){
            count[i]++;
        }
        // unordered_map<int,int> ogCount = count;
        int doublesFound=0;
        sort(arr.begin(),arr.end());
        for (int i:arr){
            if ((i!=0 && count[i]!=0 && count[i*2]!=0) || (i==0 && count[i]!=0 && count[0]%2==0)){
                // doubleCount[i]++;
                count[i*2]--;
                count[i]--;
                doublesFound++;
            }
        }
        
        return doublesFound>= arr.size()/2;   
    }
};