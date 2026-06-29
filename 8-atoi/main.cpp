#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string digits = "";
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i]) || (s[i] == '-' && digits.length() == 0) || (s[i] == '+' && digits.length() == 0)){
                digits += s[i];
            } else if(s[i] == ' ' && digits.length() == 0){
                continue;
            } else if(digits.length() > 0){
                break;
            } else if (s[i] != ' ' && digits.length() == 0){
                return 0;
            }
        }
        if (digits.length() == 0) return 0;
        long long result = 0;
        for (int i = 0; i < digits.length(); i++) {
            if (i == 0 && (digits[i] == '-' || digits[i] == '+')) continue;
            result = result * 10 + (digits[i] - '0');
            if (result > INT_MAX) {
                return digits[0] == '-' ? INT_MIN : INT_MAX;
            }
        }
        return digits[0] == '-' ? -(int)result : (int)result;
    }
};