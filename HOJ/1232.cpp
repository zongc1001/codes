#include <cstdio>
#include <vector>
using namespace std;

int far[1000 + 5];
int n, m;

//寻找祖先结点
int find(int cur)
{

    vector<int> temp; //存下搜索路径中的结点
    while (cur != far[cur])
    {
        temp.push_back(cur);
        cur = far[cur];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        far[temp[i]] = cur;
    }

    return cur;
}

void combine(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    far[fa] = fb;
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0)
            break;
        else
            scanf("%d", &m);
        for (int i = 1; i <= n; i++)
        {
            far[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            combine(a, b);
        }

        unsigned int res = -1;
        for (int i = 1; i <= n; i++)
        {
            if (i == far[i])
                res++;
        }

        printf("%d\n", res);
    }

    return 0;
}