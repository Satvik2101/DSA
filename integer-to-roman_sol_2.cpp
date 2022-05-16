#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    void addLetters(string &s,char c, int count){
        while (count--){
            s+=c;
        }
    }
    string intToRoman(int num) {
      
// making a string array with all possible strings**
string s[] = {"M", "CM", "D","CD","C","XC","L","XL","X", "IX","V","IV", "I"};

string result = "";              

// making an array with the values in same manner as the string array. 
int arr[] = { 1000 , 900 , 500 ,400,100, 90, 50, 40,10,9,5,4, 1 };

for(int i = 0 ; num > 0  ; i++){               // while num>0 we need to run this loop , therefore execution time is less 
    while(num >= arr[i]){
            result += s[i];
            num=num- arr[i];
        
        }
        }
        return result;
    }
};