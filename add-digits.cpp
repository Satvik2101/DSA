#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        int curSum = 0;
        while (num){
            if (num<10 && curSum ==0)break;
            curSum += num%10;
            num/=10;
            if (num==0){
                num=curSum;
                curSum = 0;
            }
        }
        return num;
    }
};