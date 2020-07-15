#include <iostream>
#include <string.h>
#include <iomanip>
#include <cmath>

using namespace std;

double arr[1010] = {0};

int main(int argc, char const *argv[])
{
    int k;

    // for(int i = 0 ; i< 1000;i++) {
    //     cout << arr[i] << " ";
    // }
    memset(arr, 0, sizeof(double) * 1010);
    while (cin >> k)
    {

        for (int i = 0; i < k; i++)
        {
            int temp;
            double num;
            cin >> temp >> num;
            // cout << temp << " " << num << " ";
            arr[temp] = num;
            // cout << temp << ": " << arr[temp] << endl;
        }
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int temp;
            double num;
            cin >> temp >> num;
            arr[temp] += num;
            // arr[temp] = ceil(arr[temp]);
            // cout << temp << ": " << arr[temp] << endl;
        }
        int nonzero = 0;
        for (int i = 1001; i >= 0; i--)
        {
            if (arr[i] != 0)
                nonzero++;
        }
        cout << nonzero;
        for (int i = 1001; i >= 0; i--)
        {
            if (arr[i] != 0)
            {
                cout << " " << i << " " << fixed << setprecision(1) << arr[i];


                // printf(" %d %.1f", i, arr[i]);
            }
        }
        cout << endl;
    }

    return 0;
}
