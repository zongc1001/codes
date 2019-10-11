#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        bool done = false;
        for(int i = 0; i < nums.size() - 1 && !done; i++) {
            for(int j = i + 1; j < nums.size() && !done; j++) {
                if(target == nums[i] + nums[j]) {
                    res[0] = i;
                    res[1] = j;
                    
                }
            }
        }
        return res;
    }
};