#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // since sorted, we use two pointers to track unique elements.
        int left = 0, right = 1;
        while (right < nums.size()){
            if (nums[right] != nums[left]){
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};