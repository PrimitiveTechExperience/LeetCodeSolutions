#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<string>> memo;
    vector<string> generateParenthesis(int n) {
        // Idea: for i = 1, its just ()
        // Insert complete brackets beside or inside any brackets
        // For subsequent n.
        memo.resize(n+1);
        memo[0] = {""};
        memo[1] = {"()"};
        for(int i = 2; i <= n; i++){
            set<string> curr;
            // Insert complete brackets beside or inside any brackets
            for (int j = 0; j < i; j++){
                for(string& s1: memo[j]){
                    for(string& s2: memo[i-1-j]){
                        curr.insert(s1 + "()" + s2);
                        curr.insert("()" + s1 + s2);
                        curr.insert(s1 + s2 + "()");
                        curr.insert("(" + s1 + ")" + s2);
                    }
                }
            }
            memo[i] = vector<string>(curr.begin(), curr.end());
        }
        return memo[n];
    }
};