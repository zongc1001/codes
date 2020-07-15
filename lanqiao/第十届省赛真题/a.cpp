#include <iostream>
#include <cmath>
using namespace std;

bool is(int n)
{
    return n == 2 || n == 0 || n == 1 || n == 9;
}

int main(int argc, char const *argv[])
{
    unsigned long long res = 0;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int x = 0; x <= 9; x++)
            {
                for (int y = 0; y <= 9; y++)
                {
                    if (is(i) || is(j) || is(x) || is(y))
                    {
                        res += (i * 1000 + j * 100 + x * 10 + j) * (i * 1000 + j * 100 + x * 10 + j);
                    }
                }
            }
        }
    }

    for(int i = 2000; i <= 2019; i++)
    {
        res += i * i;
    }


    cout << res << endl;            //2748729470

    return 0;
}
