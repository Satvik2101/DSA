#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll int t;
    cin >> t;
    while (t--) {
        ll int width, height;
        cin >> width >> height;
        ll int n;
        cin >> n;
        ll int xCoordinates[n];
        ll int yCoordinates[n];
        for (ll int i = 0; i < n; i++) {
            cin >> xCoordinates[i];
            cin >> yCoordinates[i];
        }
        ll int maxXDiff = 0;
        ll int maxYDiff = 0;
        sort(xCoordinates, xCoordinates + n);
        sort(yCoordinates, yCoordinates + n);
        for (ll int i = 0; i < n; i++) {
            if (i == 0) {
                if (xCoordinates[i] - 1 > maxXDiff) {
                    maxXDiff = xCoordinates[i] - 1;
                }
                if (yCoordinates[i] - 1 > maxYDiff) {
                    maxYDiff = yCoordinates[i] - 1;
                }
                continue;
            }

            if (xCoordinates[i] - xCoordinates[i - 1] - 1 > maxXDiff) {
                maxXDiff = xCoordinates[i] - xCoordinates[i - 1] - 1;
            }
            if (yCoordinates[i] - yCoordinates[i - 1] - 1 > maxYDiff) {
                maxYDiff = yCoordinates[i] - yCoordinates[i - 1] - 1;
            }
        }
        if (width - xCoordinates[n - 1] > maxXDiff) {
            maxXDiff = width - xCoordinates[n - 1];
        }
        if (height - yCoordinates[n - 1] > maxYDiff) {
            maxYDiff = height - yCoordinates[n - 1];
        }
        cout << (maxXDiff) * (maxYDiff) << endl;
    }
    return 0;
}
