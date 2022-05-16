#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
// Question Link :https://www.spoj.com/problems/DIEHARD/
// kbx2157
using namespace std;
// H,A
pair<int, int> getChange(char medium) {
    switch (medium) {
    case 'A':
        return {3, 2};
    case 'W':
        return {-5, -10};
    case 'F':
        return {-20, 5};
    default:
        return {0, 0};
    }
}
int main() {

    int T;
    cin >> T;
    while (T--) {
        int H, A;
        cin >> H >> A;

        char medium = 'A';
        int clock = 0;

        while (H > 0 && A > 0) {
            pair<int, int> change = getChange(medium);
            H += change.first;
            A += change.second;
            // cout << H << " " << A << endl;
            char newMedium = 'x';
            switch (medium) {
            case 'A':
                newMedium = (H > 5 && A > 10) ? 'W' : 'F';
                break;
            case 'W':
            case 'F':
                newMedium = 'A';
                break;
            default:
                newMedium = 'X';
            }

            medium = newMedium;
            clock++;
            // cout << medium << " ";
        }
        clock = clock == 0 ? 1 : clock;
        cout << clock - 1 << endl;
    }
    return 0;
}