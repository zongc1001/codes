#include <cstdio>

using namespace std;

bool debug = false;
int n, m;
int arr[25][25];

unsigned long long res = 0;
double count = 0;
bool visited[25];

void dfs(int start, int last, int cur, int time)
{
    if (debug)
    {
        printf("enter dfs: start=%d last=%d cur=%d time=%d\n",
               start, last, cur, time);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int temp = arr[cur][i];
        if (temp != 0 && (last != i) && !visited[i])
        {
            visited[i] = true;
            if (debug)
            {
                printf("set %d true\n", i);
            }
            flag = false;
            dfs(start, cur, i, time + 1);
            visited[i] = false;
            if (debug)
            {
                printf("set %d false\n", i);
            }
        }
    }
    if (flag)
    {
        res += time;
        count++;
        if (debug)
        {
            printf("reach dest, time=%d, res:%d, count=%d\n", time, res, count);
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
        debug = true;
    if (debug)
    {
        freopen("51", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        res = 0;
        count = 0;
        visited[i] = true;
        if (debug)
        {
            printf("set %d true\n", i);
        }
        dfs(i, -1, i, 0);
        visited[i] = false;
        if (debug)
        {
            printf("set %d false\n", i);
        }
        double temp = res / count;
        printf("%lf\n", temp);
    }

    return 0;
}
