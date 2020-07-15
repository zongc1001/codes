#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> table;
    void creatTable(int n) {
        n++;
        table.assign(n, 0);
        table[0] = 1;
        table[1] = 1;
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i; j++) {
                table[i] += table[j] * table[i - 1 - j];
            }
        }
    }
    int numTrees(int n) {
        creatTable(n);
        return table[n];
    }
};

