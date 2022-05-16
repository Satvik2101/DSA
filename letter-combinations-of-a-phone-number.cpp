#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
   vector<string> mp = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
    vector<string> ans;
    vector<string> temp;
    void addToAns(){
        for (string s:temp){
            ans.push_back(s);
        }
        for (int i =0;i<temp.size();i++){
            temp[i]=temp[i].substr(0,temp[i].length()-1);
        }
    }
    void generate(string digits,int index){
        if (index==digits.length()){
            addToAns();
            return;
        }
        string letterList = mp[(digits[index]-'2')];
        if (index==0){
            for (char c :letterList){
                string s="";
                s+=c;
                temp.push_back(s);
            }
        }else{
            int ogTempSize= temp.size();
            for (int i =0;i<ogTempSize;i++){
                string s = "" +temp[i];
                for (int j = 0; j< letterList.length();j++){
                    if (j==0){
                        temp[i] = s + letterList[j];
                    }else{
                        temp.push_back(s+letterList[j]);
                    }
                }
            }
        }
        generate(digits,index+1);
    }
    vector<string> letterCombinations(string digits) {
       
        if (digits.length()==0) return ans;
        generate(digits,0);
        return ans;
        
    }
};