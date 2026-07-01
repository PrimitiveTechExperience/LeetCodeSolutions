#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Since we are restricted to only 0, 1, 2, we can simply count the number of 0s, 1s, and 2s, and then overwrite the original array with the correct number of each.
        int count[3] = {0, 0, 0};
        for (int num : nums){
            count[num]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < count[i]; j++){
                nums[index++] = i;
            }
        }
    }
};