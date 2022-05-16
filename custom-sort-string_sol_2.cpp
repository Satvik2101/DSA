#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_multiset<char> elements;
        for (char c:s){
            elements.insert(c);
        }
        string ans = "";
        
        for (char c:order){
            auto it = elements.find(c);
            while (it!=elements.end()){
                ans+=c;
                elements.erase(it);
                it = elements.find(c);
            }
        }
        for (char c:elements){
            ans+=c;
        }
        return ans;
    }
};