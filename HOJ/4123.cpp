/*
http://acm.hdu.edu.cn/showproblem.php?pid=4123
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <fstream>
using namespace std;

int m, n;
typedef pair<int, int> road;
typedef vector<road> roads;
typedef unsigned long long ll;
vector<roads> tree;
vector<ll> dis1;
vector<bool> visited;
ll mm[50000 + 10][20];
ll mi[50000 + 10][20];

void dfs(int cur, ll distance)
{
    visited[cur] = true;
    if (distance > dis1[cur])
    {
        dis1[cur] = distance;
    }
    for (int i = 0; i < tree[cur].size(); i++)
    {
        road &temp = tree[cur][i];
        if (!visited[temp.first])
        {
            dfs(temp.first, distance + temp.second);
        }
    }
}

int queryDiff(int left, int right)
{
    if (left == right)
        return 0;
    int k = 0;
    while (left + (1 << k) <= right)
        k++;
    // cout << "k: " << k << endl;
    return max(mm[left][k - 1], mm[right - (1 << (k - 1)) + 1][k - 1]) -
           min(mi[left][k - 1], mi[right - (1 << (k - 1)) + 1][k - 1]);
}

int main(int argc, char const *argv[])
{
    // streambuf *backup;
    // ifstream temp;
    // temp.open("in.txt");
    // backup = cin.rdbuf();
    // cin.rdbuf(temp.rdbuf());

    while (scanf("%d %d", &n, &m) != EOF && n && m)
    {
        tree.resize(n + 1);
        for(int i = 1; i <= n;i++)
        {
            tree[i].clear();
        }
        // cout <<"--------------" << endl;
        // for(int i = 1; i <= n;i++)
        // {
        //     cout <<tree[i].size() << " ";
        // }
        // cout << endl;
        
        for (int i = 0; i < n - 1; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            tree[a].push_back(road(b, c));
            tree[b].push_back(road(a, c));
        }

        dis1.assign(n + 1, 0);
        visited.assign(n + 1, false);
        // cout << "-----------------" << endl;
        // for(int i = 1; i<= n;i++)
        // {
        //     cout << dis1[i] << " ";
        // }
        // cout << endl;
        dfs(1, 0);
        int maxTemp = 0;
        int index = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dis1[i] > maxTemp)
            {
                maxTemp = dis1[i];
                index = i;
            }
        }
        visited.assign(n + 1, false);
        dfs(index, 0);
        maxTemp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis1[i] > maxTemp)
            {
                maxTemp = dis1[i];
                index = i;
            }
        }
        visited.assign(n + 1, false);
        dfs(index, 0);
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << dis1[i] << " ";
        // }
        // cout << endl;

        for (int i = 1; i <= n; i++)
        {
            mm[i][0] = mi[i][0] = dis1[i];
        }
        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                mm[i][j] = max(mm[i][j - 1], mm[i + (1 << (j - 1))][j - 1]);
                mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 0; j <= 4; j++)
        //     {
        //         cout << mi[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << queryDiff(1, 2) << endl;

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = i; j <= n; j++)
        //     {
        //         cout << queryDiff(i, j) << " ";
        //     }
        //     cout << endl;
        // }

        while (m--)
        {
            int q;
            cin >> q;
            if(q <= 0)
            {
                cout << n << endl;
                continue;
            }
            int l, r;
            l = r = 1;
            int res = -1;
            while (r <= n && l <= n)
            {
                ll tempRes = queryDiff(l, r);
                if (tempRes <= q)
                {
                    res = max(res, r - l + 1);
                    r++;
                }
                else
                {
                    l++;
                }
                
            }

            cout << res << endl;
        }
    }
    return 0;
}
