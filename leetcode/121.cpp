#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int last = 0, res = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            last = max(0, last + prices[i] - prices[i - 1]);
            res = max(res, last);
        }
        return res;
    }
};