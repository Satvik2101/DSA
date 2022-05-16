#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    vector<int> stack;
    int lastFilled;
    int max;
    CustomStack(int maxSize) {
        stack = vector<int> (maxSize,0);
        lastFilled=-1;
        max = maxSize;
    }
    
    void push(int x) {
        if (lastFilled+1>=max) return;
        stack[++lastFilled] =x;
    }
    
    int pop() {
        if (lastFilled==-1) return -1;
        return stack[lastFilled--];
    }
    
    void increment(int k, int val) {
        int n = min(k,max);
        for (int i = 0;i<n;i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */