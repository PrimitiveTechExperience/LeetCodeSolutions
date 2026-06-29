#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> can_reach(nums.size(), false);
        can_reach[0] = true;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                for (int j = i + 1; j <= i + nums[i] && j < nums.size(); j++){
                    can_reach[j] = can_reach[j] || can_reach[i] || i == 0;
                }
            }
            if (can_reach[nums.size() - 1]) break;
        }
        return can_reach[nums.size() - 1];
    }
};