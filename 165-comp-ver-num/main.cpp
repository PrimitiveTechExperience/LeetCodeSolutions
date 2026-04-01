#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> revisions1 = split(version1);
        vector<int> revisions2 = split(version2);
        for(int i = 0; i < revisions1.size() || i < revisions2.size(); i++){
            int rev1 = i < revisions1.size() ? revisions1[i] : 0;
            int rev2 = i < revisions2.size() ? revisions2[i] : 0;
            if(rev1 > rev2) return 1;
            else if(rev1 < rev2) return -1;
        }
        return 0;
    }
private:
    vector<int> split(string& version){
        vector<int> rev;
        int start = 0;
        for(int i = 0; i < version.size(); i++){
            if(version[i] == '.'){
                rev.push_back(stoi(version.substr(start, i-start)));
                start = i + 1;
            }
        }
        rev.push_back(stoi(version.substr(start)));
        return rev;
    }
};