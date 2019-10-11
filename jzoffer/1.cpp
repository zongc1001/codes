#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0 || array[0].size() == 0) {
            return false;
        }
        for(int i = 0; i < array.size();i++) {
            if(target >= array[i][0]) {
                for(int j = 0; j < array[i].size();j++) {
                    if(target == array[i][j]) {
                        return true;
                    }
                    else if (target < array[i][j]) {
                        break;
                    }
                }
            } 
            else {
                break;
            }
        }
        return false;
    }
};


