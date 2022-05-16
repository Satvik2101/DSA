#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
     
        int n    = image.size();
        int m = image[0].size();
        int mid = m/2;

       
        for(int i =0; i<n; i++)
        {
            m = image[i].size();
            if(m%2!=0)
            {
                for(int j =0; j<=mid; j++)
                {
                    image[i][m-1] = image[i][m-1]^1;
                    --m;

                    if(m!=j)
                    {
                        image[i][j] = image[i][j]^1;    
                    }
                    swap(image[i][j], image[i][m]);

                }    
            }
            else
            {
                for(int j =0; j<mid; j++)
                {
                    image[i][m-1] = image[i][m-1]^1;
                    --m;
               
                    if(m!=j)
                    {
                        image[i][j] = image[i][j]^1;    
                    }
                    swap(image[i][j], image[i][m]);
                }
            }
            
        }
        return image;
    }
    
};