#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/grid-illumination

class Solution {
private:

    bool isValid(int i, int j, int n) {
        return (i >= 0 && j >= 0 && i < n && j < n);
    }



    int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};
public:

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        set<pair<int, int>> cells;
        unordered_map<int, int> r, c, d1, d2;


        for (auto l : lamps) {
            if (cells.count({l[0], l[1]})) continue; // dont consider it if this was already seen

            // for this bulb, increment the count of bulbs in its row col , primary and secondary diagonal
            r[l[0]]++;
            c[l[1]]++;
            d1[l[0] + l[1]]++;
            d2[l[0] - l[1]]++;
            cells.insert({l[0], l[1]});
        }
        vector<int> ans;
        for (auto q : queries) {

            // to check whether this cell is illuminated or not, check whether this row/col/primary-diagonal/sec-diagonal contains a bulb, if yes it means this cell is illuminated

            if (r[q[0]] > 0 || c[q[1]] > 0 || d1[q[0] + q[1]] > 0 || d2[q[0] - q[1]] > 0) {
                ans.push_back(1);

                // check all the eight neighbours, if there is a bulb anywhere, first remove that bulb from the cells list and then decrement the count of bulbs by 1, in the corresponding row, col, primary and secondary diagonals
                for (auto d : dirs) {
                    int ni = q[0] + d[0];
                    int nj = q[1] + d[1];
                    if (isValid(ni, nj, n) && cells.count({ni, nj})) {
                        r[ni]--; c[nj]--; d1[ni + nj]--; d2[ni - nj]--; cells.erase({ni, nj});
                    }
                }

                // if this cell itself contains a bulb, repeat the same procedure for this bulb as well
                if (cells.count({q[0], q[1]})) {
                    cells.erase({q[0], q[1]});
                    r[q[0]]--;
                    c[q[1]]--;
                    d1[q[0] + q[1]]--;
                    d2[q[0] - q[1]]--;

                }
            } else ans.push_back(0);
        }

        return ans;
    }

};