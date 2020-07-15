#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    unsigned long ans = n;
    while(n >= 3)
    {
        int temp = n / 3;
        ans += temp;
        n = n - temp * 2;
    }

    

    cout << ans << endl;

    return 0;
}
