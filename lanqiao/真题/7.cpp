#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int min = 0x7fffffff;
        int max = -1;
        for (int j = i; j < n; j++)
        {

            if (vec[j] > max)
                max = vec[j];
            if (vec[j] < min)
                min = vec[j];

            if (j - i == max - min)
                res++;
        }
    }
    cout << res << endl;

    return 0;
}
