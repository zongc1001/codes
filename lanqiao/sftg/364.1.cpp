#include <cstdio>
#include <vector>
using namespace std;
bool debug = false;
int n;
int arr[2000 + 5];
int mem[2000 + 5];
int res = 0;

void dfs(int pos, int value, int size)
{
    if (size == 3 && mem[pos] > -1)
    {
        res += mem[pos];
    }
    else
    {
        int temp = 0;
        for (int i = pos + 1; i < n && i + 3 - size < n; i++)
        {
            if (arr[i] > value)
            {
                if (size == 3)
                {
                    res++;
                }
                else
                {
                    dfs(i, arr[i], size + 1);
                }
                temp++;
            }
        }
        mem[pos] = temp;
    }
}

int main(int argc, char const *argv[])
{
    debug = argc > 1;
    if (debug)
        freopen("364", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    vector<int> bigger(n);

    fill(bigger.begin(), bigger.end(), 0);

    fill(mem, mem + 2000 + 5, -1);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                bigger[i]++;
            }
        }
    }

    for (int i = 0; i < n - 3; i++)
    {
        dfs(i, arr[i], 1);
    }
    printf("%d\n", res);
    return 0;
}
