#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
// Question Link : https://www.spoj.com/problems/DEFKIN/
// kbx2157
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int w, h, n;
        cin >> w >> h >> n;
        if (n == 0) {
            cout << w * h << endl;
            continue;
        }
        vector<int> xCoordinates(n + 2);
        vector<int> yCoordinates(n + 2);
        xCoordinates[0] = 0;
        yCoordinates[0] = 0;

        for (int i = 0; i < n; i++) {
            cin >> xCoordinates[i + 1] >> yCoordinates[i + 1];
        }
        xCoordinates[n + 1] = w + 1;
        yCoordinates[n + 1] = h + 1;
        sort(xCoordinates.begin(), xCoordinates.end());
        sort(yCoordinates.begin(), yCoordinates.end());

        int maxXDiff = 0, maxYDiff = 0;
        for (int i = 1; i < n + 2; i++) {
            maxXDiff = max(maxXDiff, xCoordinates[i] - xCoordinates[i - 1]);
            maxYDiff = max(maxYDiff, yCoordinates[i] - yCoordinates[i - 1]);
        }
        cout << (long long)(maxXDiff - 1) * (long long)(maxYDiff - 1) << endl;
    }

    // 3,8,11
    // 2,6,8

    return 0;
}