#include <iostream>
#include <string>
using namespace std;

int res[10000];

int to8(unsigned long long n)
{
    int s = 0;
    
    int cur = 0;
    while(n > 0)
    {
        // cout << "n: " << n << endl;
        int temp = n % 8;
        // cout << "temp: " << temp << endl;

        res[cur++] = temp;
        n -= temp;
        n /= 8;

    }
    cout << 0;
    while(cur)
    {
        cout << res[--cur];    //
    }
    cout << endl;
    return s;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // cout << '0' << to8(n) << endl;
    to8(n);
    return 0;
}
