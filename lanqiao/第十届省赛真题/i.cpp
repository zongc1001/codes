#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Obj
{
    unsigned long long product;
    int sum;
    int num;
    Obj(unsigned long long pro = 1, int s = 0, int n = 0)
        : product(pro), sum(s), num(n) {}
    bool operator<(Obj a)
    {
        return num > a.num;
    }
};

unsigned long long fact(unsigned long long n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
int sumation(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sumation(n - 1);
}

Obj arr[105];
bool ex[22] = {false};
int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    unsigned long long targetPro = fact(m);
    int targetSum = sumation(m);
    for (int i = 0; i < n; i++)
    {
        vector<bool> exist(ex, ex + m);
        for (int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            if (!exist[temp])
            {
                arr[i].sum += temp;
                arr[i].product *= temp;
                arr[i].num++;
                exist[temp] = true;
            }
        }
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].product << "  " << arr[i].sum << "  " << arr[i].num << endl;
        
        
    }

    






    return 0;
}
