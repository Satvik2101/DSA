// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> colors;
bool canColor(bool graph[101][101], int node, int color, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && colors[i] == color)
            return false;
    }
    return true;
}

bool solve(bool graph[101][101], int node, int m, int n) {
    if (node == n) {
        return true;
    }
    for (int i = 0; i < m; i++) {
        if (canColor(graph, node, i, n)) {
            colors[node] = i;
            bool isThisValid = solve(graph, node + 1, m, n);
            if (isThisValid)
                return true;
        }
    }
    colors[node] = -1;
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // colors vary from 0 to m-1, -1 means uncolored;
    colors = vector<int>(n, -1);
    return solve(graph, 0, m, n);
}

// { Driver Code Starts.

int main() {

    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++) {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;

    return 0;
}
// } Driver Code Ends