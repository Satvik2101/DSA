#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0,right = 0;
        int len = s.length();
        
        int ans = 0;
        
        vector<int> included (256,-1) ;
        
        while (left<=right && right<len){
            int currChar = s[right];
            // cout<<right<<endl;
            if (included[currChar] != -1){
                int index = included[currChar];
                if (left<index+1){
                    left = index+1;
                }
                included[currChar] = -1;
            }else{
                included[currChar] = right;
                // cout<<left<<" "<<right<<endl;
                ans  = max(ans,right-left+1);
                right++;
            }
        }
        return ans;
    }
};