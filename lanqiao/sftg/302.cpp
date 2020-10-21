#include <iostream>
#include <cmath>
using namespace std;
int arr[10005];
int findMin(int a, int b, int c)
{
    if (b < a)
        a = b;
    if (c < a)
        a = c;
    return a;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    if (n < 3)
    {
        cout << 0 << endl;        
        return 0;
    }
    arr[n] = 0;
    int min = 0x7fffffff;
    for (int i = 0; i < 3; i++)
    {
        min = min < arr[i] ? min : arr[i];
    }
    if (n == 3)
    {
        cout << min << endl;
        return 0;
    }
    int a, b, c;
    a = arr[0], b = arr[1], c = arr[2];
    int res;
    for (int i = 3; i < n + 1; i++)
    {
        // cout << a << " " << b << " " << c << endl;
        res = arr[i] + findMin(a, b, c);
        a = b;
        b = c;
        c = res;
    }
    cout << res << endl;
    return 0;
}
