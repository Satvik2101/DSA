#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/count-primes

bool isPrime(int n)
{
    for (int i =2;i<=sqrt(n);i++)
    {
        if (n%i==0)return false;
    }
    return true;
}
class Solution {
public:
    
    int countPrimes(int n) {
        int count =0;
        for (int i =2;i<n;i++)
        {
            if (isPrime(i)) count++;
        }
        return count;
    }
};