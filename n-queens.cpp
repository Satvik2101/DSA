// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> board;
    vector<vector<int>> ans;

    unordered_set<int> rows;
    unordered_set<int> plusDiags;  // x+y;
    unordered_set<int> minusDiags; // x-y;

    bool isSafe(int row, int col) {
        if (rows.find(row) != rows.end())
            return false;
        if (plusDiags.find(row + col) != plusDiags.end())
            return false;
        if (minusDiags.find(row - col) != minusDiags.end())
            return false;
        if (board[row][col] == 1)
            return false;
        return true;
    }
    int n;

    bool solve(int col) {
        // cout << col << endl;
        if (col > n) {
            cout << "WTF";
            return false;
        }
        if (col == n) {
            vector<int> curr;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1)
                        curr.push_back(j + 1);
                }
            }
            ans.push_back(curr);
            // cout << "pushing back ans";
            return true;
        }

        bool ans;
        for (int i = 0; i < n; i++) {

            if (isSafe(i, col)) {
                // cout << i << " " << col << endl;
                board[i][col] = 1;
                rows.insert(i);
                plusDiags.insert(i + col);
                minusDiags.insert(i - col);

                ans = solve(col + 1) | ans;

                board[i][col] = 0;
                rows.erase(i);
                plusDiags.erase(i + col);
                minusDiags.erase(i - col);
            } else {
                // cout << i << " " << col << " not safe" << endl;
                // cout << (rows.find(i) != rows.end()) << endl;
                // cout << (plusDiags.find(i + col) != plusDiags.end()) << endl;
                // cout << (minusDiags.find(i - col) != minusDiags.end()) <<
                // endl; cout << (board[i][col] == 1) << endl; cout <<
                // "------------------------------------" << endl;
            }
        }
        return ans;
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        this->n = n;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        if (solve(0) == false)
            return {};
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends