#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    double l = 0, r = 1.0; // we can take min,max too

    while (l < r) {
        double mid = (l + r) / 2;
        // maxLessThanMid is used to store the maximum fraction less than mid
        double maxLessThanMid = 0.0;
        // maxI and maxJ are used for storing the indices of max fraction
        int totalNoLessThanMid = 0, maxI = 0, maxJ = 0;
        int j = 1;
        for (int i = 0; i < n - 1; i++) {
            // if this fraction is greater than mid , move denominator
            // rightwards to find a smaller mid
            // cout<<arr[i]<<" "<<arr[j]<<" "<<mid;
            while (j < n && arr[i] > mid * arr[j])
                j++;
            // j elements are greater than mid in this row , n-j are smaller ,
            // add them to result
            totalNoLessThanMid += (n - j);
            if (j == n)
                break;
            // cast to double speedily
            double f = static_cast<double>(arr[i]) / arr[j];
            // update max fraction for this mid
            if (f > maxLessThanMid) {
                maxI = i;
                maxJ = j;
                maxLessThanMid = f;
            }
        }
        if (totalNoLessThanMid == k)
            return {arr[maxI], arr[maxJ]};
        // there are too many fractions less than mid=> mid is too big => make
        // mid smaller and try
        else if (totalNoLessThanMid > k)
            r = mid;
        // too less fractions less than mid, i.e. mid is too small => make mid
        //  bigger and try
        else
            l = mid;
    }
    return {};
}
};