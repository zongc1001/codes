//http://lx.lanqiao.cn/problem.page?gpid=T563

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[13][13];
struct point
{
    int x, y, val;
    point(int a, int b, int c)
    {
        x = a;
        y = b;
        val = c;
    }
    bool up()
    {
        return x != 0;
    }
    bool right()
    {
        return y != n-1;
    }
};

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<point> q;
    q.push(point(n - 1, 0, arr[n - 1][0]));
    vector<int> v;
    while (!q.empty())
    {
        point temp = q.front();
        q.pop();
        if (temp.x == 0 && temp.y == n - 1)
        {
            // cout << temp.x << " " << temp.y << endl;
            v.push_back(temp.val);
            continue;
        }
        if (temp.right())
        {
            q.push(point(temp.x, temp.y + 1, temp.val + arr[temp.x][temp.y+1]));
        }
        if (temp.up())
        {
            q.push(point(temp.x - 1, temp.y, temp.val + arr[temp.x -1][temp.y]));
        }
        
    }
    sort(v.begin(), v.end());
    int res = 0;
    // cout << v.size() << endl;
    for(int i = v.size() - 1; i >=0; i--)
    {
        res += v[i] == v.back();
    }
    // cout <<endl;
    cout << res << " " << v.back() << endl;

    return 0;
}
