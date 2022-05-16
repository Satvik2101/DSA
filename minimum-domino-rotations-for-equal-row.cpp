#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int topFreq[6] = {0, 0, 0, 0, 0, 0};
    int bottomFreq[6] = {0, 0, 0, 0, 0, 0};

    for (int i : tops) {
        topFreq[i - 1]++;
    }

    for (int i : bottoms) {
        bottomFreq[i - 1]++;
    }
    bool possible[6] = {false, false, false, false, false};

    for (int i = 0; i < 6; i++) {
        if ((topFreq[i] + bottomFreq[i]) >= tops.size()) {
            possible[i] = true;
        }
    }

    int count = INT_MAX;
    for (int i = 0; i < 6; i++) {
        if (!possible[i])
            continue;
        bool isPossible = true;
        int rotateToBottom = 0;
        int rotateToTop = 0;
        for (int j = 0; j < tops.size(); j++) {
            if ((tops[j] != i + 1) && (bottoms[j] != i + 1)) {
                isPossible = false;
                break;
            }
            if (tops[j] == i + 1 && bottoms[j] == i + 1)
                continue;
            else if (tops[j] == i + 1) {
                rotateToBottom++;
            } else if (bottoms[j] == i + 1) {
                rotateToTop++;
            }
        }
        if (isPossible) {
            count = min(count, min(rotateToBottom, rotateToTop));
        }
    }
    return count == INT_MAX ? -1 : count;
        
    }
};