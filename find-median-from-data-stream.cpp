#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
    
    void balance(){
        while (nLeft-nRight>1){
            right.push(left.top());
            left.pop();
            nRight++;
            nLeft--;
        }
        while (nRight-nLeft>1){
            left.push(right.top());
            right.pop();
            nRight--;
            nLeft++;
        }
    }
    
public:
    //We will keep this sorted
    priority_queue<int> left; //max heap
    priority_queue<int,vector<int>,greater<int>> right; //min heap
    int nLeft =0;
    int nRight =0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (nLeft==0 && nRight==0){
            left.push(num);
            nLeft++;
        }else if (num<left.top()){
            left.push(num);
            nLeft++;
        }else{
            right.push(num);
            nRight++;
        }
        balance();
    }
    
    double findMedian() {
        if (nLeft<nRight){
            return right.top();
        }
        if (nLeft>nRight){
            return left.top();
        }
        double ans = (double)(left.top()+right.top());
        return ans/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */