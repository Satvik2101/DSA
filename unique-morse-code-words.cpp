#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string dict[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> unique;
        for (string word:words){
            string temp="";
            for (char c:word){
                temp+=dict[c-'a'];
            }
            unique.insert(temp);
        }
        return unique.size();
    }
};