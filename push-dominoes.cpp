#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/push-dominoes

class Solution {
public:
    
    struct Domino{
        char dir;
        int time;
    };
    string pushDominoes(string dominos) {
         int n = dominos.length();
    vector<Domino> status(n, {'.', 0});
    int timestamp = 0;

    // Left to right pass;
    bool rightFalling = false;
    // cout << dominos << endl;
    for (int i = 0; i < n; i++) {
        char c = dominos[i];
        if (c == 'R') {
            timestamp = 0;
            status[i].time = 0;
            status[i].dir = 'R';
            rightFalling = true;
        }
        if (c == 'L') {
            status[i].dir = 'L';
            timestamp = 0;
            rightFalling = false;
        }

        if (c == '.' && rightFalling) {
            status[i].time = (++timestamp);
            status[i].dir = 'R';
        }
    }
    // printDominos(status);
    // Right to left pass;
    dominos = "";
    for (Domino domino : status) {
        dominos += domino.dir;
    }
    bool leftFalling = false;
    timestamp = 0;
    for (int i = n - 1; i >= 0; i--) {
        char c = dominos[i];
        if (c == 'L') {
            timestamp = 0;
            status[i].time = 0;
            status[i].dir = 'L';
            leftFalling = true;
        }
        if (c == 'R' && leftFalling) {

            if (status[i].time == (++timestamp)) {
                status[i].dir = '.';
                timestamp = 0;
                leftFalling = false;
            } else if (status[i].time < timestamp) {
                status[i].dir = 'R';
                timestamp = 0;
                leftFalling = false;
            } else {
                status[i].dir = 'L';
            }
        }
        if (c == '.' && leftFalling) {
            status[i].time = ++timestamp;
            status[i].dir = 'L';
        }
    }
    // printDominos(status);

    string ans = "";
    for (Domino domino : status) {
        ans += domino.dir;
    }
    return ans;
    }
};