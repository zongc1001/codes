#include <iostream>

using namespace std;

unsigned long long arr[101][101];
int main(int argc, char const *argv[])
{
    int k, l;
    
    cin >> k >> l;
    
    for (int i = 0; i < k; i++)
    {
        arr[0][i] = 1;
    }
    
    for (int i = 1; i < l; i++)
    {
        for (int j = 0; j < k; j++)
        {
            unsigned long long sum = 0;
            for (int t = 0; t < k; t++)
            {
                if (t != j + 1 && t != j - 1)
                {
                    sum += arr[i - 1][t];
                    if(sum >= 1000000007)
                    {
                        sum -= 1000000007;
                    }
                }
            }
            arr[i][j] = sum;
        }
    }
    
    unsigned long long res = 0;
    
    for (int i = 1; i < k; i++)
    {
        res += arr[l - 1][i];
        res = res >= 1000000007 ? res - 1000000007 : res;
    }
    cout << res << endl;
    return 0;
}
