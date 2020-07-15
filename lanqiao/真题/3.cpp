#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool visited[10];

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    int res = 0;
    int a;       //整数
    double b, c; // 分子  分母
    do
    {
        a = 0;
        for (int i = 0; (i < 9) && (a * 10 + arr[i] < n); i++)
        {

            a = a * 10 + arr[i]; //整数部分
            int remainder = n - a; //余数部分
            bool notFoundRes = true;
            b = 0;
            for (int j = i + 1; j < i + (8 - i) / 2 + 1 && notFoundRes; j++)
            {
                b = b * 10 + arr[j];
                c = 0;
                for (int t = j + 1; t < 9 && notFoundRes; t++)
                {
                    c = c * 10 + arr[t];
                }
                double temp = c / b;
                if (temp == remainder)
                {
                    res++;
                    notFoundRes = false;
                    // cout << a << " " << b << " " << c << endl;
                    // for (int i = 0; i < 9; i++)
                    // {
                    //     cout << arr[i] << " ";
                    // }
                    // cout << endl;
                }
            }
        }
    } while (next_permutation(arr, arr + 9));

    cout << res << endl;

    return 0;
}
