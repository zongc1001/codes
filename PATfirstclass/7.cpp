#include <iostream>
#include <stack>
using namespace std;

int arr[10010];
int main(int argc, char const *argv[])
{
    int k;

    bool noPositive = true, exitZero = false;

    long long resSum = 0;
    int resStart, resEnd;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        if (noPositive && arr[i] > 0)
        {
            noPositive = false;
        }
        if(!exitZero && arr[i] == 0)
        {
            exitZero = true;
        }
    }
    arr[k] = 0;

    if (noPositive)
    {
        if(exitZero)
            cout << "0 0 0" << endl;
        else 
            cout << 0 << " " << arr[0] << " " << arr[k - 1] << endl;
        return 0;
    }

    long long sum = 0;
    int start = 0, end = 0;
    stack<int> s;
    while (end <= k)
    {
        if (sum < 0)
        {
            sum = 0;
            while (!s.empty())
            {
                start++;
                s.pop();
            }
        }
        else
        {
            s.push(arr[end++]);
            sum += s.top();
            if (sum > resSum)
            {
                resSum = sum;
                resStart = start;
                resEnd = end - 1;
            }
        }
    }
    


    cout << resSum << " " << arr[resStart] << " " << arr[resEnd] << endl;

    // cout << resSum << " " << resStart << " " << resEnd << endl;

    return 0;
}