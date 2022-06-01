#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

// kbx2157
using namespace std;
class Solution {
  public:
    // unordered_multiset<char> characters;
    int count[26];
    vector<string> ans;

    void dfs(string current) {
        // cout << current << endl;
        bool end = true;
        for (int i = 0; i < 26; i++) {

            if (count[i] > 0) {
                end = false;
                char c = i + 'A';
                // cout << c << " ";
                current += c;
                count[i]--;

                dfs(current);
                count[i]++;
                current.pop_back();
            }
        }
        if (end)
            ans.push_back(current);
    }

    vector<string> find_permutation(string S) {
        //  characters = unordered_multiset<char>(S.begin(),S.end());
        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= 'A' && S[i] <= 'Z') {
                count[S[i] - 'A']++;
            } else {
                count[S[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++)
            cout << count[i] << " ";
        string curr = "";
        dfs(curr);
        return ans;
        // Code here there
    }
};
int main() {

    Solution sol;
    vector<string> ans = sol.find_permutation("BBA");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}