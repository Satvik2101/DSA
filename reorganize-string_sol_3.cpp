#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        // bool possible = true;
        vector<int> freq(26,0);
        for (char c:s)freq[c-'a']++;
        int maxFreq=0;
        char mostCommon = -1;
        for (int i = 0;i<26;i++){
            if (freq[i]>maxFreq){
                maxFreq = freq[i];
                mostCommon = 'a'+i;
            }
        }
        
        int index = 0;
        if (maxFreq > (s.length()+1)/2) return "";
        string output = s;
        while (freq[mostCommon-'a'] !=0 ){
            output[index] = mostCommon;
            index += 2;
            freq[mostCommon-'a']--;
        }
        
        for (int i = 0;i<26;i++){
            while (freq[i]!=0){
                if (index >= s.length()) index = 1;
                output[index] = i+'a';
                freq[i]--;
                index+=2;
            }
        }
        return output;
    }
    
};