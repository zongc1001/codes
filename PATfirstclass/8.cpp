#include <iostream>

using namespace std;

int arr[105];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int cur = 0;
    int total = 0;
    while(n--)
    {
        int temp;
        cin >> temp;
        if(cur < temp)
        {
            total += (temp - cur) * 6 + 5;
        }
        else if(cur > temp)
        {
            total += (cur - temp) * 4 + 5;
        }
        else 
        {
            total += 5;
        }
        cur = temp;
    }
    cout << total << endl;






    return 0;
}
