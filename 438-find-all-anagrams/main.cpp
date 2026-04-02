#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Just count occurances of chars in p then sliding window to finish
        unordered_map<char, int> freq = count_chars(p);
        vector<int> result;
        for(int i = 0; i + p.size() <= s.size(); i++){
            string window = s.substr(i, p.size());
            unordered_map<char, int> window_freq = count_chars(window);
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