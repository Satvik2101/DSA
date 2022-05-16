#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
     
        int n = image.size();
        int m = (n&1)?n/2:n/2-1;
        
        for (int i = 0;i<n;i++){
            for (int j = 0; j<=m; j++){
                image[i][j] = !image[i][j];
                swap(image[i][j],image[i][n-j-1]);
                if (j!=n/2)
                    image[i][j] = !image[i][j];

            }
        }
        return image;
        
    }
};