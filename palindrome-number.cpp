#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    
    int count(int n){
        int ans =0;
        while(n){
            ans++;
            n/=10;
        }
        return ans;
    }
    int getIthDigit(int n,int cnt, int i){
        //int cnt = count(n);
        for (int k =0;k<cnt-i;k++){
            n/=10;
        }
        return n%10;
    }
    bool isPalindrome(int x) {
        if (x<0) return false;
        int ogX = x;
        int cnt = count(x);
        
        for (int i =0;i<cnt/2;i++){
            if (x%10 != getIthDigit(ogX,cnt,i+1)){
                return false;
            }
            x/=10;
        }
        return true;
    }
};