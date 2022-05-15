#include <iostream>
#include <unordered_map>
// kbx2157
//  Question Link :
//  https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#
using namespace std;
class DLLNode {
  public:
    int val;
    DLLNode *post;
    DLLNode *pre;

    DLLNode() {
        post = NULL;
        pre = NULL;
    }
    DLLNode(int val) {
        this->val = val;
        this->post = NULL;
        this->pre = NULL;
    }

    DLLNode(DLLNode *other) {
        this->val = other->val;
        this->post = other->post;
        this->pre = other->pre;
    }
};
class LRUCache {
    // These are dummy nodes, the actual nodes will be between these nodes
    // This is to avoid null checks at multiple places.
    DLLNode *head;
    DLLNode *tail;

    // We always add to front of the list, to keep the most recent node on head;
    void addNode(DLLNode *newNode) {
        newNode->pre = head;
        newNode->post = head->post;
        head->post->pre = newNode;
        head->post = newNode;
    }

    void removeNodeFromList(DLLNode *node) {
        // We would generally need to check here if node->post is NULL or not
        // But since we're using dummy nodes we know that all our nodes
        // will have a post and a pre, except tail and head
        node->post->pre = node->pre;
        node->pre->post = node->post;
    }
    void deleteNode(DLLNode *node) {

        removeNodeFromList(node);
        delete node;
    }

    void moveToHead(DLLNode *node) {
        removeNodeFromList(node);
        addNode(node);
    }

    int popTail() {
        DLLNode *preTail = tail->pre;
        int key = preTail->val;
        deleteNode(preTail);
        return key;
    }

    unordered_map<int, DLLNode *> cache;
    int count;

    int capacity;

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = new DLLNode();
        tail = new DLLNode();
        head->post = tail;
        head->pre = NULL;
        tail->pre = head;
        tail->post = NULL;
    }

    // returns true if new val was inserted
    // if already present, returns false
    bool put(int val) {
        if (cache.find(val) == cache.end()) {
            count++;
            DLLNode *node = new DLLNode(val);
            addNode(node);
            cache.insert({val, node});
            // If capacity full, remove the least recently used node (the node
            // at tail)
            if (count > capacity) {
                int poppedKey = popTail();
                cache.erase(poppedKey);
                count--;
            }
            return true;
        } else {
            DLLNode *node = cache[val];
            // Accessed recently, so it should be at head.
            moveToHead(node);
            return false;
        }
    }
};

int pageFaults(int N, int C, int pages[]) {
    // code here
    LRUCache cache(C);

    int count = 0;

    for (int i = 0; i < N; i++) {
        int page = pages[i];
        bool fault = cache.put(page);
        if (fault)
            count++;
    }
    return count;
}
int main() {
    LRUCache cache(2);
    cout << cache.put(1) << endl;
    cout << cache.put(1) << endl;
    cout << cache.put(2) << endl;
    cout << cache.put(3) << endl;
    cout << cache.put(1) << endl;
    cout << cache.put(3) << endl;
}