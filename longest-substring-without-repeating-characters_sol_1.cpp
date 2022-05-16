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
        
        unordered_map<char,int> included;
        
        while (left<=right && right<len){
            int currChar = s[right];
            // cout<<right<<endl;
            if (included.find(currChar) != included.end()){
                int index = included[currChar];
                if (left<index+1){
                    left = index+1;
                }
                included.erase(currChar);
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