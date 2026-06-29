#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        string result = "";
        for (auto it = roman.rbegin(); it != roman.rend(); it++){
            while (num >= it->first){
                result += it->second;
                num -= it->first;
            }
        }
        return result;
    }
};