//https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

typedef unsigned short ushort;
typedef vector<int> vectorint;
ushort far[10000 + 5];
int n;
vector<vectorint> table;
vector<bool> visited;
vector<int> dist;

ushort find(ushort a)
{
    vector<ushort> v;
    while (a != far[a])
    {
        v.push_back(a);
        a = far[a];
        // printf("2312312");
    }
    for (int i = 0; i < v.size(); i++)
    {
        far[v[i]] = a;
    }
    return a;
}

void combine(int a, int b)
{
    ushort fa = find(a);
    ushort fb = find(b);
    far[fa] = fb;
}

bool isError()
{
    int part = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == find(i))
        {
            part++;
        }
    }
    if (part != 1)
    {
        printf("Error: %d components\n", part);
        return true;
    }
    else
        return false;
}

int dfsToFindDeepest(int cur)
{
    // printf("entry dfsToFindDeepest, cur=%d\n", cur);
    queue<int> q;

    int curDeep = -1;
    q.push(cur);
    while (!q.empty())
    {
        int loopsize = q.size();
        curDeep++;
        while (loopsize--)
        {
            int temp = q.front();
            visited[temp] = true;
            if (curDeep > dist[temp])
                dist[temp] = curDeep;
            q.pop();
            for (int i = 0; i < table[temp].size(); i++)
            {
                if (!visited[table[temp][i]])
                {
                    q.push(table[temp][i]);
                }
            }
        }
    }
    return curDeep;
}

int main()
{
    scanf("%d", &n);
    table.assign(n + 1, vectorint());
    visited.assign(n + 1, false);
    dist.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        far[i] = i;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        combine(a, b);
        table[a].push_back(b);
        table[b].push_back(a);
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     printf("%d\n", far[i]);
    // }
    if (isError())
        return 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d: ", i);
    //     for (int j = 0; j < table[i].size(); j++)
    //     {
    //         printf("%d ", table[i][j]);
    //     }
    //     printf("\n");
    // }
    visited.assign(n + 1, false);

    // printf("deepest road: %d\n", dfsToFindDeepest(1));
    int deepest = dfsToFindDeepest(1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == deepest)
        {

            deepest = dfsToFindDeepest(i);
            break;
        }
    }
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == deepest)
        {

            deepest = dfsToFindDeepest(i);
            break;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(dist[i] == deepest)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}