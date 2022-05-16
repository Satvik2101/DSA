#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        stack<int> s;
        for (int i:asteroids){
            if (s.empty()){
                s.push(i);
                continue;
            }
            if ((s.top()<0 && i>0) || (s.top()*i>0)) {
                //same sign
                s.push(i);
                continue;
            }else{
                int curr = -(i);
                bool add = true;
                while ((!s.empty()) && ((s.top()>0) && (i<0))){
                    int top = (s.top());
                    if (curr>top){
                        // cout<<"popping "<<s.top();
                        s.pop();
                    } else if (curr==top){
                        s.pop();
                        add= false;
                        break;
                    }else {
                        add = false;
                        break;
                    }
                }
                if (add) s.push(i);

            }
        }
        
        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};