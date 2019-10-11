#include <iostream>
#include <hash_map>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        short carr[256] = {0};
        int len = s.length();
        vector<char> vec;
        int i,j;
        for(i = j = 0; i < len && j < len; j++) {
            i = max(i, (int)carr[s[j]]);
            res = max(res, j - i + 1);
            carr[s[j]] = j + 1;
        }
        return res;
    }
};