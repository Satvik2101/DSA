#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/merge-k-sorted-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        int nullLists = 0;
        ListNode* newHead = new ListNode(0);
        ListNode* newHeadCopy = newHead;
        while (nullLists<k){
            //Find minimum value;
            int curMin = INT_MAX;
            int minIndex = -1;
            for (int i = 0 ;i<k;i++){
                //cout<<"i: "<<i<<endl;
                if (lists[i]==NULL) continue;
                //cout<<i<<" "<<lists[i]->val<<" "<<curMin<<endl;
                if (lists[i]->val<curMin){
                    curMin= lists[i]->val;
                    minIndex = i;
                  //  cout<<"here :"<<minIndex<<endl;
                }
            }
            //cout<<minIndex;
            if (minIndex == -1){
              //  cout<<"returning";
                return newHeadCopy->next;
            }
            lists[minIndex]= lists[minIndex]->next;
            if (lists[minIndex]==NULL){
                nullLists++;
            }
            newHead->next = new ListNode(curMin);
            newHead = newHead ->next;
        }
        return newHeadCopy->next;
    }
};