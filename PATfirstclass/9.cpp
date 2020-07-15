#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double arr1[1005];
int index1[1005];
double arr2[1005];
int index2[1005];
double res[2005];

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int exp;
        double co;
        cin >> exp >> co;
        arr1[exp] = co;
        index1[i] = exp;
    }
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        int exp;
        double co;
        cin >> exp >> co;
        arr2[exp] = co;
        index2[i] = exp;
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            res[index1[i] + index2[j]] += arr1[index1[i]] * arr2[index2[j]];
        }
    }
    int sum = 0;
    for (int i = 2004; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            sum++;
        }
    }
    cout << sum;
    for (int i = 2004; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            cout << " " << i << " "<<fixed << setprecision(1) << res[i];
        }
    }
    cout << endl;

    return 0;
}
