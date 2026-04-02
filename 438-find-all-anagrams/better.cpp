#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Just count occurances of chars in p then sliding window to finish
        unordered_map<char, int> freq = count_chars(p);
        vector<int> result;
        string window = s.substr(0, p.size());
        unordered_map<char, int> window_freq = count_chars(window);
        if (window_freq == freq){
            result.push_back(0);
        }
        for(int i = 1; i + p.size() <= s.size(); i++){
            // Only update the window freq instead of recounting every time
            char left = s[i-1];
            char right = s[i + p.size() - 1];
            window_freq[left]--;
            if (window_freq[left] == 0) window_freq.erase(left);
            window_freq[right]++;
            if (window_freq == freq){
                result.push_back(i);
            }
        }
        return result;
    }
private:
    unordered_map<char, int> count_chars(const string& str){
        unordered_map<char, int> freq;
        for (char c: str){
            freq[c]++;
        }
        return freq;
    }
};