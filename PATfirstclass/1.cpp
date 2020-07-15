#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    while (cin >> a >> b)
    {

        int sum = a + b;
        if (sum == 0)
        {
            cout << 0 << endl;
            continue;
        }

        bool isNeg = false;
        if (sum < 0)
        {
            isNeg = true;
            sum *= -1;
        }
        vector<int> a;
        while (sum > 0)
        {
            a.push_back(sum % 1000);
            sum /= 1000;
        }

        reverse(a.begin(), a.end());
        int len = a.size();
        int index = 0;

        if (isNeg)
            cout << '-';

        cout << a[index++];
        while (index < len)
        {
            cout << ",";
            int temp = a[index++];
            if (temp >= 100)
                cout << temp;
            else if (temp >= 10)
            {
                cout << '0' << temp;
            }
            else
            {
                cout << "00" << temp;
            }
        }

        cout << endl;
    }
    return 0;
}
