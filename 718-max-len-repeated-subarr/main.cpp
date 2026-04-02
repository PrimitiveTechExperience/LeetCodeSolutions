#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // More sliding window but with dynamic programming
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0)); 
        // Want: A[i:] and B[j:] longest in memo[i][j] (prefix since longest sub is annoying to calculate)
        int maxLength = 0;
        for (int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(nums1[i] == nums2[j]){
                    memo[i][j] = 1 + memo[i + 1][j + 1];
                    maxLength = max(maxLength, memo[i][j]);
                }
            }
        }
        return maxLength;
    }
};