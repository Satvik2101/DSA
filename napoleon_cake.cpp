#include <iostream>
#include <vector>
// kbx2157
// Question Link :https://codeforces.com/contest/1501/problem/B
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> drenched(n, 0);

        vector<int> cream(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> cream[i];
        }

        int curr = cream[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            if (cream[i] > curr) {
                curr = cream[i];
            }
            if (curr) {
                drenched[i] = 1;
                curr--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << drenched[i] << " ";
        }
        cout << endl;
    }
}