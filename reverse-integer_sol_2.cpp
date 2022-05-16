#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

   
        while (x){
            int toBeAdded = x%10;
            if (x>0 && ans>(INT_MAX-toBeAdded)/10){
                return 0;
            }
            if (x<0 && ans< (INT_MIN-toBeAdded)/10){
                return 0;
            }
                ans = ans*10+toBeAdded;
            
            x/=10;
        }
     
        return ans;
    }
};