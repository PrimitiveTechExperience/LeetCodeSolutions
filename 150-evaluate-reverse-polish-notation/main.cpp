#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands; 
        for (string& token: tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                if (token == "+") operands.push(a + b);
                else if (token == "-") operands.push(a - b);
                else if (token == "*") operands.push(a * b);
                else if (token == "/") operands.push(a / b);
            }
            else{
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
};