#include <iostream>
#include <cmath>
using namespace std;

bool isExactDiv(double a, int b)
{
    double temp = a / b;

    return temp == floor(temp);
}

int main(int argc, char const *argv[])
{
    double arr[3];
    int res = 1;
    int max = -1;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int product = 2;

    while (product <= max)
    {

        bool is = true;
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == 1)
                continue;
            if (!isExactDiv(arr[i], product))
            {
                is = false;
                break;
            }
        }

        if (is)
        {
            for (int i = 0; i < 3; i++)
            {
                if (arr[i] != 1)
                    arr[i] /= product;
            }
            res *= product;
            if (arr[0] == 1 && arr[1] == 1 && arr[2] == 1)
                break;
        }
        else
        {
            product++;
            continue;
        }
    }
    cout << isExactDiv(4, 4) << endl;
    cout << res << endl;
    return 0;
}
