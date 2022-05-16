#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int pivotIndex = points.size();
        int left = 0;
        int right = pivotIndex-1;
        
        while (pivotIndex!=k){
            pivotIndex = partition(points,left,right);
            // cout<<pivotIndex<<" ";
            if (pivotIndex<k){
                left = pivotIndex;
            }else{
                right = pivotIndex -1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k); 
    }
    
    int partition(vector<vector<int>> &arr, int left, int right){
        int middle = (left+right)/2;
        // cout<<left<<" "<<middle<<" "<<right<<endl;
        if (middle!= left && middle!=right)swap(arr[right],arr[middle]);
        vector<int> pivot = arr[right];
        
        int pivotDistance = dist(pivot);
        int partitionIndex = left-1;
        for (int iterator = left;iterator<right;iterator++){
            if (dist(arr[iterator]) <= pivotDistance){
                swap(arr[++partitionIndex],arr[iterator]);
            }
        }
        swap(arr[++partitionIndex],arr[right]);
        return partitionIndex;
    }
    int dist(const vector<int> &point) const{
        return point[0]*point[0] + point[1]*point[1];
    }
};