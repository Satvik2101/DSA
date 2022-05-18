#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
// Question Link :
// https://practice.geeksforgeeks.org/problems/rearrange-characters/0
//  kbx2157
using namespace std;
string lessThanNine(int S, int D) {
    if (S > 9 || D > 9)
        return ""; // ERROR CONDITION
    string ans = "";
    if (D == 1) {
        ans += S + '0';
        return ans;
    }
    ans += '1';
    D--;
    S--;
    while (D > 1) {
        ans += '0';
        D--;
    }
    ans += (S + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}
string smallestNumber(int S, int D) {
    if (S > 9 * D)
        return "-1";
    string ans = "";
    while (S > 9) {
        ans += "9";
        S -= 9;
        D--;
    }
    ans += lessThanNine(S, D);
    reverse(ans.begin(), ans.end());
    return ans;
    // code here
}
int main() {

    cout << smallestNumber(3, 4);
    return 0;
}