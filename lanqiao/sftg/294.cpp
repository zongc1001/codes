/*
http://lx.lanqiao.cn/problem.page?gpid=T563
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned int uint;
struct point
{
    /* data */
    uint height;
    int x, y;
    int len;
    point(uint h, int i, int j, int l) : height(h), x(i), y(j), len(l){};
    bool operator<(point &obj)
    {
        return this->height > obj.height;
    }
};

int m, n;
uint height[13][13];
int step[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int main(int argc, char const *argv[])
{
    cin >> m >> n;
    vector<point> vec;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            uint temp;

            cin >> temp;
            height[i][j] = temp;
            vec.push_back(point(temp, i, j, 1));
        }
    }
    for (int i = 0; i <= n + 1; i++)
    {
        height[0][i] = 0x7fffffff;
        height[m + 1][i] = 0x7fffffff;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        height[i][0] = 0x7fffffff;
        height[i][n + 1] = 0x7fffffff;
    }

    sort(vec.begin(), vec.end());

    int Max = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        // cout << vec[i].height << endl;
        queue<point> q;
        q.push(vec[i]);
        while (!q.empty())
        {
            point &tempPoint = q.front();
            q.pop();
            if (tempPoint.len > Max)
                Max = tempPoint.len;
            for (int j = 0; j < 4; j++)
            {
                int x = tempPoint.x + step[j][0];
                int y = tempPoint.y + step[j][1];
                if (tempPoint.height > height[x][y])
                {
                    q.push(point(height[x][y], x, y, tempPoint.len + 1));
                }
            }
        }
        if (Max == m * n)
            break;
    }
    cout << Max << endl;

    return 0;
}
