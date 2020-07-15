#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> edge;

int n;
vector<vector<edge> > dis;
vector<bool> vistied;

int res = -1;
int dst = 0;
void recur(int cur, int distance)
{
    // cout << cur << "  "<<distance << endl;
    if (distance >= res)
    {
        res = distance;
        dst = cur;
    }
    if (vistied[cur])
    {
        return;
    }
    vistied[cur] = true;
    for (int i = 0; i < dis[cur].size(); i++)
    {
        edge &temp = dis[cur][i];
        if (!vistied[temp.first])
            recur(temp.first, distance + temp.second);
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    dis.resize(n + 1);
    vistied.resize(n + 1);
    int sumOfEdge = 0;

    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a].push_back(edge(b, c));
        dis[b].push_back(edge(a, c));
        sumOfEdge += c;
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j < dis[i].size(); j++)
    //     {
    //         cout << "table: " << i << "  "<<dis[i][j].first << " " << dis[i][j].second << endl;
    //     }
    // }

    vistied.resize(n + 1, false);
    recur(1, 0);
    // cout <<"dst: " <<dst << endl;
    vistied.clear();
    vistied.resize(n + 1, false);
    recur(dst, 0);

    // cout << res << endl;
    cout << res * 11 + res * (res - 1) / 2 << endl;

    return 0;
}
