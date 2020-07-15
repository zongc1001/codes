//http://lx.lanqiao.cn/problem.page?gpid=T15
#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

int n, m;
typedef vector<int> ints;
struct e
{
    int from, to, weight;
    e() { from = to = weight = 0; }
    e(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

int main(int argc, char const *argv[])
{

    scanf("%d %d", &n, &m);
    vector<int> dist(n + 1);
    vector<e> edge(m);
    
    dist[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dist[i] = 10000 * 20000 + 10;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edge[i].from = a;
        edge[i].to = b;
        edge[i].weight = c;
    }

    for (int i = 1; i <= n; i++)
    {
        bool prebreak = true;
        for (int j = 0; j < m; j++)
        {
            if (dist[edge[j].to] > dist[edge[j].from] + edge[j].weight)
            {
                dist[edge[j].to] = dist[edge[j].from] + edge[j].weight;
                prebreak = false;
            }
        }
        if(prebreak) break;
    }

    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", dist[i]);
    }

    return 0;
}
