#include <cstdio>

using namespace std;

int n;
int arr[2000 + 5];
int res = 0;
void dfs(int pos, int value, int size)
{
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
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 3; i++)
    {
        dfs(i, arr[i], 1);
    }
    printf("%d\n", res);
    return 0;
}
