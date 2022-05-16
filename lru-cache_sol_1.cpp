#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/lru-cache

class LRUCache {
    
    class DLLNode{
        public:
        int key;
        int value;
        DLLNode *pre;
        DLLNode *post;
        
        DLLNode(){}
        DLLNode(DLLNode* other){
            this->key = other->key;
            this->value = other->value;
            this->pre = other->pre;
            this->post = other->post;
        }
        DLLNode(int key, int value){
            this->key = key;
            this->value = value;
        }
    };
    DLLNode* head;
    DLLNode* tail;
    
    void addNode(DLLNode *node){
        node->pre = head;
        node->post = head->post;
        head->post->pre = node;
        head->post = node;
    }
    
    void removeNode(DLLNode *node){
        node->pre->post = node->post;
        node->post->pre = node->pre;
        delete node;
    }
    
    DLLNode* moveToHead(DLLNode* node){
        int key = node->key;
        int value = node->value;
        removeNode(node);
        DLLNode* copy = new DLLNode(key,value);
        addNode(copy);
        return copy;
    }
    
    DLLNode *popTail(){
        DLLNode *preTail = tail->pre;
        DLLNode* copy = new DLLNode(preTail->key, preTail->value);
        removeNode(preTail);
        return copy;
    }
    
    
    unordered_map<int,DLLNode* > cache;
    int count = 0;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new DLLNode();
        head->pre = NULL;
        tail = new DLLNode();
        tail->post  = NULL;
        head->post = tail;
        tail->pre = head;
    }
    
     int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        DLLNode *node = cache[key];
        int val = node->value;
        cache[key]=moveToHead(node);
        return val;
    }

    
    void put(int key, int value) {
        if (cache.find(key)==cache.end()){
            DLLNode *newNode = new DLLNode();
            newNode->key = key;
            newNode->value = value;
            cache.insert({key,newNode});
            addNode(newNode);
            count++;
            
            if (count>capacity){
                DLLNode* tailNode = popTail();
                cache.erase(tailNode->key);
                count--;
            }
        }else{
            DLLNode* node = cache[key];
            node->value = value;
            cache[key]=moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */