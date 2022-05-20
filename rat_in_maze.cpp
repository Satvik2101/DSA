

#include <bits/stdc++.h>
using namespace std;
class Solution {

    // possible = 1, obstacle = 0, visited = 2
    vector<vector<int>> m;
    map<char, pair<int, int>> directions = {
        {'L', {0, -1}}, {'R', {0, 1}}, {'D', {1, 0}}, {'U', {-1, 0}}};
    int n;

    bool safe(int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n || m[row][col] == 0 ||
            m[row][col] == 2) {
            return false;
        }
        return true;
    }
    vector<string> possiblePaths;

    void recurPath(int row, int col, string &currentPath) {
        if (!safe(row, col))
            return;
        if (row == n - 1 && col == n - 1) {
            possiblePaths.push_back(currentPath);
            return;
        }
        m[row][col] = 2;

        for (auto it = directions.begin(), end = directions.end(); it != end;
             it++) {
            int newRow = row + (it->second).first;
            int newCol = col + (it->second).second;
            // cout << newRow << " " << newCol << endl;
            if (!safe(newRow, newCol))
                continue;
            currentPath.push_back(it->first);
            recurPath(newRow, newCol, currentPath);
            currentPath.pop_back();
        }
        m[row][col] = 1;
    }

  public:
    vector<string> findPath(vector<vector<int>> &obstacleMap, int n) {
        m = obstacleMap;
        this->n = n;
        string path = "";
        recurPath(0, 0, path);
        return possiblePaths;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends