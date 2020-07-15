#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(int argc, char const *argv[])
{
    do
    {
        if (arr[0] == 0)
            continue;

        for (int i = 0; i < 9; i++)
        {
            unsigned long long a = 0, b = 0;
            if (arr[i + 1] == 0)
                continue;
            for (int j = 0; j <= i; j++)
            {
                a *= 10;
                a += arr[j];
            }
            for (int j = i + 1; j <= 9; j++)
            {
                b *= 10;
                b += arr[j];
            }
            // cout << a << " " << b << endl;
            if(pow( sqrt(a), 3) == b)
            {
                cout << sqrt(a) << " " << a << " " << b << endl;
                
            }
        }

    } while (next_permutation(arr, arr + 10));

    return 0;
}
