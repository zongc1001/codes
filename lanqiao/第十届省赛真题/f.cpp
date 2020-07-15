#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int max = -1;
    int res = 0;
    for (int i = 1; i <= log2(n + 1); i++)
    {
        int sum = 0;
        for (int j = pow(2, i - 1); j <= pow(2, i) - 1; j++)
        {
            int temp ;
            cin >> temp;
            sum += temp;

        }
        if(sum > max)
        {
            max = sum;
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}
