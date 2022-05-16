#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    struct Point{
        int x;
        int y;
        bool isStart;
        Point(int x,int y, bool isStart):x(x),y(y),isStart(isStart){}
        Point(){
            x = -1;
            y = -1;
            isStart = false;
        }
         bool operator == (const Point &other) const{
            return x == other.x && y== other.y && isStart == other.isStart;
        }
        bool operator < (const Point &other) const{
            if (x!=other.x) return x < other.x;
            if (isStart && other.isStart)return y>other.y;
            if (!isStart && !other.isStart) return y<other.y;
            return y>other.y;
        }
       
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        set<Point> points;
        
        for (vector<int>& building:buildings){
            int l = building[0];
            int r = building[1];
            int h = building[2];
            auto it = points.find(Point(l,h,false));
            if (it!= points.end()) points.erase(it);
            else points.insert(Point(l,h,true));
            points.insert(Point(r,h,false));
        }
        
        multiset<int> heights;
        heights.insert(0);
        int currentMax = 0;
        vector<vector<int>> ans;
        for (const Point &point:points){
            // cout<<point.x<<" "<<point.y<<" "<<point.isStart<<endl;
            currentMax = *(heights.rbegin());
            if (point.isStart){
                 if (point.y> currentMax){
                     ans.push_back({point.x,point.y});
                 }
                heights.insert(point.y);
            }else{
                auto itr = heights.find(point.y);
                if (itr!=heights.end()) heights.erase(itr);
                // heights.erase(point.y);
                if (*(heights.rbegin()) != currentMax){
                    // cout<<*(heights.rbegin())<<" "<<currentMax<<endl;
                    ans.push_back({point.x,*(heights.rbegin())});
                }
            }
        }
        return ans;
    }
};