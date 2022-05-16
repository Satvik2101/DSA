#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    
    class Element{
        public:
        int val,x,y;
        Element(int x,int y, int val): x(x),y(y),val(val){}
      
        bool operator < (const Element &other)const{
            return this->val < other.val;
        }
        
        bool operator > (const Element &other) const{
            return this->val>other.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<Element,vector<Element>,greater<Element>> pq;
        for (int i = 0;i<m;i++) pq.push(Element(0,i,matrix[0][i]));
        
        for (int i = 0;i<k-1;i++){
            Element smallest = pq.top();
            pq.pop();
            if (smallest.x == n-1)continue;
            pq.push(Element(smallest.x+1,smallest.y,matrix[smallest.x+1][smallest.y]));
        }
        return pq.top().val;
    }
};