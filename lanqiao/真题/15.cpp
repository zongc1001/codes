#include <iostream>
#include <cstring>
using namespace std;

bool arr[2][1010];
int res = 0;  //结果
int done = 0; //一轮dfs中已经刷好的格子
int n;

int up[2][3] = {0, 1, 0, -1, 0, 1};

int down[2][3] = {0, -1, 0, -1, 0, 1};

void dfs(int row, int col)
{
    cout << row << "  " << col << endl;
    arr[row][col] = true;
    done++;
    if (done == n * 2)
    {
        res++;
        if (res >= 1000000007)
        {
            res -= 1000000007;
        }
    }
    else
    {
        if (row == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                if (!arr[row + up[0][i]][col + up[1][i]])
                {
                    dfs(row + up[0][i], col + up[1][i]);
                }
            }
        }
        else if (row == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                if (!arr[row + down[0][i]][col + down[1][i]])
                {
                    dfs(row + down[0][i], col + down[1][i]);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        memset(arr, false, 2 * 1010 * sizeof(bool));
        arr[0][0] = arr[1][0] = arr[0][n + 1] = arr[1][n + 1] = true;
        done = 0;
        dfs(0, i);
    }
    res *= 4;
    int temp = res;
    if (n & 1)
    {
        memset(arr, false, 2 * 1010 * sizeof(bool));
        arr[0][0] = arr[1][0] = arr[0][n + 1] = arr[1][n + 1] = true;
        done = 0;
        dfs(0, n / 2 + 1);
    }
    res = temp + 2 * (res - temp);
    cout << res << endl;

    return 0;
}
