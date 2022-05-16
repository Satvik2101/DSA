#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    unordered_map<int,int> indexOf;
    vector<int> values;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (indexOf.find(val) != indexOf.end()) return false;
        
        values.push_back(val);
        indexOf.insert({val,values.size()-1});
        return true;
    }
    
    bool remove(int val) {
        if (indexOf.find(val) == indexOf.end()) return false;
        int index = indexOf[val];
        int last = values.size()-1;
        indexOf[values[last]] = index;
        swap(values[index],values[last]);
        values.pop_back();
        indexOf.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */