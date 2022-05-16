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
        string ans = "";
        int mCount = num/1000;
        addLetters(ans,'M',mCount);
        num = num%1000;
        int cCount = num/100;
        if (cCount == 9){
            ans += "CM";
            cCount = 0;
        }
        if (cCount == 4){
            ans += "CD";
            cCount = 0;
        }
        if (cCount>=5){
            ans+='D';
            cCount -=5;
        }
        addLetters(ans,'C',cCount);
        num = num%100;
         int xCount = num/10;
        if (xCount == 9){
            ans += "XC";
            xCount = 0;
        }
        if (xCount == 4){
            ans += "XL";
            xCount = 0;
        }
        if (xCount>=5){
            ans+='L';
            xCount -=5;
        }
        addLetters(ans,'X',xCount);
        num = num%10;
         int iCount = num;
        if (iCount == 9){
            ans += "IX";
            iCount = 0;
        }
        if (iCount == 4){
            ans += "IV";
            iCount = 0;
        }
        if (iCount>=5){
            ans+='V';
            iCount -=5;
        }
        addLetters(ans,'I',iCount);
        return ans;
    }
};