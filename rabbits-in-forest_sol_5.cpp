#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    map<int,int> m;
    int ceil(int x, int y){
        if ((x/y)*y == x) {
            return x/y;
        }
        return x/y+1;
    }
    int numRabbits(vector<int>& answers) {
        for (int i :answers){
            m[i]++;
        }
        int ans = 0;
        for (pair<int,int> p:m){
            if (p.first == 0){
                ans+= p.second;
            }else if (p.first>1){
                int x = p.second;
                int y = p.first;
                cout<<x<<" "<<y<<endl;
                if (x>y+1){
                    ans+= ceil(x,y+1)*(y+1);
                }
                else ans+=y+1;
            }else{
                ans+=ceil(p.second,2)*2;
            }
            //cout<<ans<<endl;
        }
        return ans;
    }
};