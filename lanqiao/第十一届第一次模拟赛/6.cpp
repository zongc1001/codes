#include <iostream>
#include <cmath>
using namespace std;

int leftMin[1000 + 10];
int rightMax[1000 + 10];
int arr[1000 + 10];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    leftMin[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMin[i] = min(leftMin[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if(arr[i] > leftMin[i-1] && arr[i] < rightMax[i+1])
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}