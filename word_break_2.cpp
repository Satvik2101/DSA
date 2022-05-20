// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<string> ans;
    unordered_set<string> dict;
    void helper(string current, string &sentence) {
        if (current.empty()) {
            ans.push_back(sentence);
            return;
        }

        string newWord = "";
        for (char c : current) {
            newWord.push_back(c);

            if (dict.find(newWord) != dict.end()) {

                sentence += newWord;
                sentence.push_back(' ');

                int len = newWord.length();

                string newCurrent = current.substr(len);
                helper(newCurrent, sentence);
                sentence = sentence.substr(0, sentence.length() - len);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string> &dictionary, string s) {
        // code here
        dict = unordered_set<string>(dictionary.begin(), dictionary.end());
        string sentence = "";
        helper(s, sentence);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends