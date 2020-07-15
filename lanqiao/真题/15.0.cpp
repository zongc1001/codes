#include <iostream>
#include <cmath>
using namespace std;

int dp[1005];
int pow2[1005];

int main(int argc, char const *argv[])
{
    int n;
    int res = 0;
    cin >> n;
    if (n == 1)
        cout << 2 << endl;
    dp[0] = dp[1] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        while (pow2[i] > 1000000007)
            pow2[i] -= 1000000007;
    }
    for (int i = 2; i <= n; i++)
    {
        int temp = pow2[i - 1];

        for (int j = i - 1; j >= 0; j--)
        {
            temp += 2 * dp[j];
            while (temp > 1000000007)
                temp -= 1000000007;
        }
        dp[i] = temp;
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == n)
        {
            res += dp[n];
            while (res > 1000000007)
                res -= 1000000007;
        }
        else
        {
            int temp = pow2[i - 1] + 2 * dp[n - i];
            while (temp > 1000000007)
                temp -= 1000000007;
            temp += pow2[n - i] + 2 * dp[i - 1];
            while (temp > 1000000007)
                temp -= 1000000007;
            res += temp;
            while (res > 1000000007)
                res -= 1000000007;
        }
    }
    res *= 2;
    while (res > 1000000007)
        res -= 1000000007;
    
    cout << res << endl;

    return 0;
}
