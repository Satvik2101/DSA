#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int first[26];
        int last[26];
        for (int i = 0;i<26;i++){
            first[i]=-1;
            last[i]=-1;
        }
        for (int i = 0;i<s.length();i++){
            int intVal = s[i]-'a';
            if (first[intVal]==-1 ){
                // cout<<s[i]<<" "<<i<<endl;
                first[intVal] = i;
                last[intVal] = i;
                continue;
            }
            if (i>last[intVal]){
                last[intVal] = i;
            }
        }
        vector<int> ans;

        int prevFirst=first[s[0]-'a'];
        int prevLast = last[s[0]-'a'];
    
        for (int c = 0;c<s.length();c++){
            int i = s[c]-'a';
            // cout<<s[c]<<" "<<prevFirst<<" "<<prevLast<<endl;
            // cout<<s[c]<<" "<<first[i]<<" "<<last[i]<<endl;
            if (first[i]==-1)continue;
            if (first[i]>prevLast){
                ans.push_back(prevLast-prevFirst+1);
                prevFirst = first[i];
                prevLast = last[i];
            }
            if (first[i]>prevFirst && last[i]<prevLast){
                continue;
            }
            if (first[i]>prevFirst && last[i]>prevLast){
                prevLast = last[i];
                continue;
            }
            
        }
        ans.push_back(prevLast-prevFirst+1);

        return ans;
    }
};