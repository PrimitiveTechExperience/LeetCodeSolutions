#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // low array length implies brute force.
        // use prefix sum arr to quickly calculate sums
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j <= n; j++){
                if (prefix[j] - prefix[i] == k){
                    count++;
                }
            }
        }
        return count;
    }
};