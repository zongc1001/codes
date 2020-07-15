#include <iostream>
#include <vector>
using namespace std;

unsigned long long res = 0;

unsigned long long dp[1000 + 5][1000 + 5];

struct matrix
{
    /* data */
    unsigned long long left, right;
    matrix(unsigned long long l, unsigned long long r) : left(l), right(r) {}
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    unsigned long long a, b;
    vector<matrix> arr;
    cin >> a;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        arr.push_back(matrix(a, b));
        a = b;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            // cout << "(" << j << ", " << j + i << ")"
            //      << " ";
            //计算 j 到 j + i 的范围上最小值
            unsigned long long min = 0x7fffffffffffffff;
            for (int k = j; k < j + i; k++)
            {

                unsigned long long temp = dp[j][k] + dp[k + 1][j + i] + arr[j].left * arr[k].right * arr[j + i].right;
                if (temp <= min)
                {
                    min = temp;
                    dp[j][j+i] = min;
                }
            }
            
        }
        // cout << endl;
    }

    
    cout << dp[0][n - 1] << endl;
    return 0;
}
