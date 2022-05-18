#include <iostream>
#include <string>
// kbx2157
// Question Link:
// https://practice.geeksforgeeks.org/contest/coding-try-outs-amazon/problems
using namespace std;

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int freq[26] = {0};
        int maxFreq = 0;
        for (char c : str) {
            freq[c - 'a']++;
            if (freq[c - 'a'] > maxFreq) {
                maxFreq = freq[c - 'a'];
            }
        }
        if (maxFreq > (str.length() + 1) / 2)
            cout << 0;
        else
            cout << 1;
        cout << endl;
    }
    return 0;
}