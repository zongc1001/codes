// 31

#include <iostream>
#include <fstream>
using namespace std;

int arr[10][10];

int main(int argc, char const *argv[])
{
    ifstream input;
    input.open("3.txt");

    unsigned long long temp = 1;
    unsigned long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int t;
            input >> t;
            temp *= t;
            if (temp >= 1000000000000)
                temp %= 10000000;
            while (temp % 10 == 0)
            {
                temp /= 10;
                ans++;

            }
            if(temp == 0) cout << "error" << endl;
            cout << temp << " ";
        }
        cout << endl;
    }

    cout << ans << endl;

    return 0;
}
