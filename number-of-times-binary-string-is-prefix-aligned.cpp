#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count=0;
        int max=-1;
        int ans = 0;
        
        for (int i:flips){
            if (i>max){
                max= i;
                count++;
            }else{
                count++;
            }
            if (max==count)ans++;
        }
        
        return ans;
    }
};