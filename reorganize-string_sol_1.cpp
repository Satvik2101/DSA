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
        
        multimap<int,char> freqMap;
        
        for (int i = 0;i<26;i++){
            if (freq[i]==0)continue;
            freqMap.insert({freq[i],i+'a'});
        }
        string ans = "";
        while (freqMap.size()>=2){
            //most freq, 2nd most freq;
            auto mostFreqIt = prev(freqMap.end());
            auto secondMostFreqIt = prev(mostFreqIt);
            if (!ans.empty() && ans.back() == mostFreqIt->second){
                ans+= secondMostFreqIt->second;
                ans+= mostFreqIt->second;
            }else{
                ans+= mostFreqIt->second;
                ans+= secondMostFreqIt->second;    
            }
            
            pair<int,char> mostFreq= *mostFreqIt;
            pair<int,char> secondMostFreq = *secondMostFreqIt;
            mostFreq.first--;
            secondMostFreq.first--;
            // cout<<"1";
            freqMap.erase(mostFreqIt);
            freqMap.erase(secondMostFreqIt);
            if (mostFreq.first) freqMap.insert(mostFreq);
            if (secondMostFreq.first) freqMap.insert(secondMostFreq);
        }
        
        if (freqMap.size()==1){
            auto element = *(freqMap.begin());
            if (element.first >1 ){
                return "";
            }
            ans += element.second;
        }
        return ans;
        
    }
};