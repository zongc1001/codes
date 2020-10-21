#include <iostream>

using namespace std;

const int MAX = 10000;

int arr[MAX + 5][50 + 5];
int n, m, c;

bool debug = false;

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        debug = true;
    }
    if (debug)
    {
        freopen("2", "r", stdin);
    }
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            int a;
            cin >> a;
            arr[i][a] = 1;
        }
    }
    if (debug)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int res = 0;
    for (int i = 1; i <= c; i++)
    {
        int lastColor = MAX * 2;

        bool founded = false;

        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 1)
            {
                if (j - lastColor > 0 && j - lastColor < m)
                {
                    res++;
                    founded = true;
                    if (debug)
                    {
                        cout << lastColor << ", " << j << endl;
                    }
                    break;
                }
                else
                {
                    lastColor = j;
                }
            }
        }
        if (!founded)
        {
            for (int j = n; j < n + m; j++)
            {
                if (debug)
                {
                    cout << "j - n:" << j - n << endl;
                }
                if (arr[j - n][i] == 1)
                {
                    if (j - lastColor < m && j - lastColor > 0)
                    {
                        res++;
                        founded = true;
                        if (debug)
                        {
                            cout << lastColor << ", " << j << endl;
                        }
                        break;
                    }
                    else
                    {
                        lastColor = j;
                    }
                }
            }
        }
        if (debug)
        {
            if (founded)
            {
                cout << "i: " << i << endl;
            }
        }
    }
    cout << res << endl;
    return 0;
}
