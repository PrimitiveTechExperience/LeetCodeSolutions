#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo;
        for(int i : nums){
            memo.push_back(INT_MAX);
        }
        memo[0] = 0;
        int steps = -1;
        for(int i = 1; i < nums.size(); i++){
            steps = memo[i-1] + 1;
            for(int j = i; j < i+nums[i-1] && j < nums.size(); j++){
                memo[j] = min(memo[j], steps);
            }
        }
        return memo.back();
    }
};