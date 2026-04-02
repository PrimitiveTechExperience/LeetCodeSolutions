#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Because sliding window increasing size is strickly an increasing
        // function, we can keep increasing the right pointer until we hit prod >= k, then move
        // left pointer until we have prod < k again. The number of subarrays ending at right pointer is right - left + 1 
        // (not including the left pointer since that would be >= k)
        int n = nums.size();
        int prod = 1, left = 0, count = 0;
        for (int right = 0; right < n; right++){
            prod *= nums[right];
            while(prod >= k && left <= right){
                prod /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};