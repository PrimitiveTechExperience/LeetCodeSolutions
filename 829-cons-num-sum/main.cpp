#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // For each k, check if n - k*(k-1)/2 is divisible by k
        int total = 0;
        for (long long k = 1; k * (k - 1) / 2 < n; ++k) {
            if ((n - k * (k - 1) / 2) % k == 0) {
                total++;
            }
        }
        return total;
    }
};