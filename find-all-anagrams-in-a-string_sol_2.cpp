#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        vector<int> freq (26,0);
        for (char c:p) freq[c-'a']++;
        unordered_map<char,int> count;
        int totalFound = 0;
        int start= 0,end = 0;
        vector<int> ans;
        while (start<s.length() && end<s.length() && start<=end){
            char c = s[end];
            if (freq[c-'a'] == 0){
                count.clear();
                start = end+1;
                end = end+1;
                totalFound = 0;
            }else{
                count[c]++;
                // cout<<c<<" "<<count[c]<<" "<<freq[c-'a']<<endl;
                if (count[c] > freq[c-'a']){
                    // cout<<start<<" "<<end<<" "<<c<<endl;
                    count.clear();
                    start = start+1;
                    end = start;
                    totalFound=0;
                }else{
                    totalFound++;
                    if (totalFound == p.length()){
                        ans.push_back(start);
                        count[s[start]]--;
                        totalFound--;
                        start++;
                    }
                    end++;
                }
            }
        }
        return ans;
    }
};