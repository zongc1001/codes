/*
问题描述
　　有一条长为n的走廊，小明站在走廊的一端，每次可以跳过不超过p格，每格都有一个权值wi。
　　小明要从一端跳到另一端，不能回跳，正好跳t次，请问他跳过的方格的权值和最大是多少？
输入格式
　　输入的第一行包含两个整数n, p, t，表示走廊的长度，小明每次跳跃的最长距离和小明跳的次数。
　　接下来n个整数，表示走廊每个位置的权值。
输出格式
　　输出一个整数。表示小明跳过的方格的权值和的最大值。
样例输入
8 5 3
3 4 -1 -100 1 8 7 6
样例输出
12
数据规模和约定
　　1<=n, p, t<=1000, -1000<=wi<=1000。
*/

#include <iostream>

using namespace std;
bool debug = false;
const int MAX = 1000;
int n = 0, p = 0, t = 0;
int arr[MAX + 5];
int dp[MAX + 5][MAX + 5];
int main(int argc, char const *argv[])
{
    if (argc > 1)
        debug = true;
    if (debug)
    {
        freopen("369", "r", stdin);
    }
    cin >> n >> p >> t;
    for(int i = 0; i < MAX + 5; i++) {
        for(int j =0; j < MAX + 5;j++) {
            dp[i][j] = -2000;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    if (t == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= p; i++)
    {
        dp[1][i] = arr[i];
    }
    for (int i = 2; i < t; i++)
    {
        for (int j = i; j <= i * p && j <= n; j++)
        {
            int _max = -2000;
            for (int x = j - 1; x >= 1 && x >= j - p; x--)
            {
                if (dp[i - 1][x] > _max)
                {
                    _max = dp[i - 1][x];
                }
            }
            dp[i][j] = _max + arr[j];
        }
    }

    if (debug)
    {
        for (int i = 1; i < t; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    int res = -2000;
    for (int i = n; i >= n - p && i >= 1; i--)
    {
        if (dp[t - 1][i] > res)
        {
            res = dp[t - 1][i];
        }
    }
    cout << res << endl;
    return 0;
}
