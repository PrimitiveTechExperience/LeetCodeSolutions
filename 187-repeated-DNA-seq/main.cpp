#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // more sliding windows.
        unordered_set<string> seen;
        unordered_set<string> repeated;
        for (int i = 0; i + 9 < s.size(); i++){
            string seq = s.substr(i, 10);
            if(seen.count(seq)){
                repeated.insert(seq);
            } else {
                seen.insert(seq);
            }
        }
        vector<string> result;
        for(const string& seq : repeated){
            result.push_back(seq);
        }
        return result;
    }
};