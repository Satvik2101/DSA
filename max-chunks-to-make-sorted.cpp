#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/max-chunks-to-make-sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax (n);
        preMax[0] = arr[0];
        for (int i = 1;i<n;i++){
            preMax[i] = max(preMax[i-1],arr[i]);
        }
        int ans=0;
        for(int i = 0;i<n;i++){
            if (preMax[i]==i)ans++;
        }
        return ans;
    }
};