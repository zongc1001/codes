#include <iostream>

using namespace std;

unsigned long edge[1000 + 5][1000 + 5] = {INT_MAX};
int dist[1000 + 5];
bool vistied[1000 + 5];

int main(int argc, char const *argv[])
{
    int m; //路径数量
    int n; //节点数量
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }
    vistied[1] = true;
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        edge[i][i] = 0;
        dist[i] = edge[1][i];
    }

    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= n;j++)
        {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }

    


    int includeNum = 1;
    while (includeNum != n)
    {
        int min = 0x7fffffff;
        int next;
        for (int i = 1; i <= n; i++)
        {
            if (edge[cur][i] < min && !vistied[i])
            {
                min = edge[cur][i];
                next = i;
            }
        }
        vistied[next] = true;
        if(next = )
        includeNum++;
        for (int i = 1; i <= n; i++)
        {
            if (!vistied[i] && edge[next][i] + dist[next] < dist[i])
            {
                dist[i] = edge[next][i] + dist[next];
            }
        }
        cur = next;
    }

    return 0;
}
