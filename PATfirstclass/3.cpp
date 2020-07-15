// https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
#include <iostream>
#include <algorithm>
using namespace std;

int n; // 城市的数量
int m; // 路的数量
int c1, c2;
int weight[510];   //各城市救援队的数量
int dis[510];      //c1到各城市的最短距离
int num[510];      //c1到各城市的最短路径的条数
int w[510];        //c1到各城市的最短路径的救援队数量之和
int e[510][510];   //两城市间的距离
bool visited[510]; //各城市是否已访问过
const int inf = 0x7fffffff;
int main(int argc, char const *argv[])
{
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int t1, t2, t3;
    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2 >> t3;
        e[t1][t2] = t3;
        e[t2][t1] = t3;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, min = inf;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dis[j] < min)
            {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1)
        {
            break;
        }
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && e[u][v] < inf)
            {
                if (dis[u] + e[u][v] < dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }
                else if (dis[u] + e[u][v] == dis[v])
                {
                    num[v] += num[u];
                    if(w[v] < weight[v] + w[u]) {
                        w[v] = weight[v] + w[u];
                    }
                }
            }
        }
    }
    cout << num[c2] << " " << w[c2] << endl;

    return 0;
}
