#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // central expansion idea
        int count = 0;
        // do odd then even length
        for (int i = 0; i < s.length(); i++){
            // odd length
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
            // even length
            left = i, right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};