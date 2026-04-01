#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Dog doo doo ahh question.
class Solution {
public:
    string numberToWords(int num) {
        // Idea: Subdivide number into thousands, millions, billions. Convert each part to words and concate.
        // Max num is int limit.
        if(num == 0) return "Zero";
        string result = "";
        if(num >= 1000000000){
            int billions = round(num / 1000000000);
            result += convert(billions) + " Billion ";
            num %= 1000000000;
        }
        if(num >= 1000000){
            int millions = round(num / 1000000);
            result += convert(millions) + " Million ";
            num %= 1000000;
        }
        if(num >= 1000){
            int thousands = round(num / 1000);
            result += convert(thousands) + " Thousand ";
            num %= 1000;
        }
        if(num > 0){
            result += convert(num);
        }
        // Remove trailing space.
        if(result.back() == ' ') result.pop_back();
        return result;
    }
private:
    string convert(int num){
        // Expects num to be less than 1000.
        int hundreds = round(num / 100);
        int tens = round((num % 100) / 10);
        int ones = num % 10;
        string result;
        switch(hundreds){
            case 1: result += "One Hundred "; break;
            case 2: result += "Two Hundred "; break;
            case 3: result += "Three Hundred "; break;
            case 4: result += "Four Hundred "; break;
            case 5: result += "Five Hundred "; break;
            case 6: result += "Six Hundred "; break;
            case 7: result += "Seven Hundred "; break;
            case 8: result += "Eight Hundred "; break;
            case 9: result += "Nine Hundred "; break;
        }

        // Account for special case: 10-19.
        if(tens == 1){
            switch(ones){
                case 0: result += "Ten"; break;
                case 1: result += "Eleven"; break;
                case 2: result += "Twelve"; break;
                case 3: result += "Thirteen"; break;
                case 4: result += "Fourteen"; break;
                case 5: result += "Fifteen"; break;
                case 6: result += "Sixteen"; break;
                case 7: result += "Seventeen"; break;
                case 8: result += "Eighteen"; break;
                case 9: result += "Nineteen"; break;
            }
            return result;
        }
        switch (tens)
        {
        case 2: result += "Twenty "; break;
        case 3: result += "Thirty "; break;
        case 4: result += "Forty "; break;
        case 5: result += "Fifty "; break;
        case 6: result += "Sixty "; break;
        case 7: result += "Seventy "; break;
        case 8: result += "Eighty "; break;
        case 9: result += "Ninety "; break;
        }
        switch (ones)
        {
        case 1: result += "One"; break;
        case 2: result += "Two"; break;
        case 3: result += "Three"; break;
        case 4: result += "Four"; break;
        case 5: result += "Five"; break;
        case 6: result += "Six"; break;
        case 7: result += "Seven"; break;
        case 8: result += "Eight"; break;
        case 9: result += "Nine"; break;
        }
        // Remove trailing space
        if(result.back() == ' ') result.pop_back();
        return result;
    }
};
