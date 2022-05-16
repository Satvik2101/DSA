#include <bits/stdc++.h>
// kbx2157
using namespace std;
// https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
     
        int n    = image.size();
        int m = n;
        int mid = m/2;
        bool flag = m%2!=0;
       
        for(int i =0; i<n; i++)
        {
            m = n;
            if(flag)
            {
                for(int j =0; j<=mid; j++)
                {
                    image[i][m-1] = !image[i][m-1];
                    --m;

                    if(m!=j)
                    {
                        image[i][j] = !image[i][j];    
                    }
                    swap(image[i][j], image[i][m]);

                }    
            }
            else
            {
                for(int j =0; j<mid; j++)
                {
                    image[i][m-1] = !image[i][m-1];
                    --m;
               
                    if(m!=j)
                    {
                        image[i][j] = !image[i][j];    
                    }
                    swap(image[i][j], image[i][m]);
                }
            }
            
        }
        return image;
    }
};
    
