#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding window idea: keep moving right until k is exhausted, then move left until k is restored.
        int left = 0, right = 0;
        int maxCount = 0;
        unordered_map<char, int> countMap;
        while (right < s.length()){
            countMap[s[right]]++;
            maxCount = max(maxCount, countMap[s[right]]);
            // if the number of chars replaced exceed k, move left ptr to restore k.
            if (right - left + 1 - maxCount > k){
                countMap[s[left]]--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};