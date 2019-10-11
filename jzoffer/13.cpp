#include<iostream>

#include<vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arr(array.size());
        int k = 0;
        for(int i = 0; i < array.size(); i++) {
            if(array[i] & 1) {
                arr[k++] = array[i];
            }
        }
        for(int i = 0 ; i < array.size(); i++) {
            if(!(array[i] & 1)) {
                arr[k++] = array[i];
            }
        }
        for(int i = 0; i < array.size() ;i ++) {
            array[i] = arr[i];
        }
    }
};