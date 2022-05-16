#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> preMax (n);
        vector<int> postMin (n);

        preMax[0] = arr[0];
        postMin[n-1]= arr[n-1];
        for (int i = 1;i<n;i++){
            preMax[i] = max(preMax[i-1],arr[i]);
            postMin[n-i-1] = std::min(postMin[n-i],arr[n-i-1]);
        }
        
        int ans=1;
        for(int i = 0;i<n-1;i++){
            if (preMax[i]<=postMin[i+1]) ans++;
        }
        return ans;
    }
};