#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    bool isNumber(char c){
        if (c<='9' && c>='0')return true;
        return false;
    }
    int myAtoi(string s) {
        int i = 0; 
        //int firstIntegerFound = false;
        bool isSignSet = false;
        bool isNegative = false;
        while (i<s.length()){
            if (s[i]=='-'){
                isNegative = true;               
            }
            if (s[i]=='-'||s[i]=='+'){
                i++;
                break;
            }
            if (isNumber(s[i])){
                break;
            }
            if (s[i]!='-' && s[i]!=' ' && s[i]!='+'){
                return 0;
            }
            i++;
        }
        if (i>=s.length()) return 0;
        cout<<s[i];
        if (!isNumber(s[i])) return 0;
        int num =(int)( s[i]-'0');
        if (isNegative){
            num = num*-1;
        }
        cout<<"initial: "<<num<<endl;
        i++;
        while (i<s.length()){
            //cout<<i<<endl;
            if (!(s[i]>='0'&& s[i]<='9')){
                return num;
            }
            int curDigit = s[i]-'0';

            if (!isNegative && (num>(INT_MAX-curDigit)/10)){
                return INT_MAX;
            }
            if (isNegative && num< (INT_MIN+curDigit)/10){
                return INT_MIN;
            }
            if (isNegative){
                num = num*10-curDigit;
            }else{
            num = num*10+curDigit;
                
            }
            cout<<num<<endl;
        i++;

        }
        return num;
    }
};