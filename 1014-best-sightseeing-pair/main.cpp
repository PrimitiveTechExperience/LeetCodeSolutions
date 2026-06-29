#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = 0, max_i = values[0] + 0;
        for (int j = 1; j < values.size(); j++) {
            best = max(best, max_i + values[j] - j);
            max_i = max(max_i, values[j] + j);
        }
        return best;
    }
};