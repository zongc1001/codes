#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> vec(n * 2);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec[i] = vec[i + n] = temp;
    }

    int sum = 0;
    int max = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if(i >= m)
        {
            max = sum > max ? sum : max;
            sum += vec[i] - vec[i-m];
        }
        else
        {
            sum += vec[i];
        }
    }
    cout << max << endl;

    return 0;
}
