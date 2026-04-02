#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        int n = nums.size();
        int sum = 0, left = 0, minLength = INT_MAX;
        for (int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (minLength == INT_MAX) return 0;
        return minLength;
    }
};