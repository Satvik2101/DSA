#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {

    public:
    vector<int> nums;
    int n;

    void printNums() {
        for (int i = 0; i < n; i++) {
            //cout << nums[i] << " ";
        }
        //cout << endl;
    }

    int findKthLargest(vector<int> &nums, int k) {
        this->nums = nums;
        this->n = nums.size();
        return kthLargest(0, n, k);
    }

    int pivot(int start, int end) {
        int pivot = nums[end - 1];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (nums[j] < pivot) {
                swap(nums[j], nums[++i]);
            }
        }
        swap(nums[++i], nums[end - 1]);
        // printNums();
        return i;
    }

    int kthLargest(int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        int len = end - start;
        int pos = pivot(start, end);
        int i = pos - start;
        if (i == len - k) {
            //cout << i << " equal " << len - k << endl;
            return nums[pos];
        }
        if (i > len - k) {
            //cout << i << " more than " << len - k << endl;
            return kthLargest(start, pos, k - len + i);
        }
        //cout << i << " less than " << len - k << endl;
        return kthLargest(pos + 1, end, k);
    }
};