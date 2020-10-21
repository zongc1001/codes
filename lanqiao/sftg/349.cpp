#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100000;


struct Obj
{
    int dest, len;
    Obj(int dest, int len)
    {
        this->dest = dest;
        this->len = len;
    }
};
int n;
vector<vector<Obj> > table;
void findDis(int src, int &dest, int &len)
{

    int max = -1;
    int res = -1;
    queue<Obj> que;
    que.push(Obj(src, 0));
    vector<bool> visited(n+1);
    visited.assign(n + 1, false);
    while (!que.empty())
    {
        int cur = que.front().dest;
        int curLen = que.front().len;
        visited[cur] = true;
        que.pop();
        // cout << "cur: " << cur << ", " << curLen << endl;
        for (int i = 0; i < table[cur].size(); i++)
        {
            int temp = table[cur][i].dest;
            int tempLen = table[cur][i].len;
                // cout << "here" << endl;
            if (!visited[temp])
            {
                if (curLen + tempLen > max)
                {
                    max = curLen + tempLen;
                    res = temp;
                }
                que.push(Obj(temp, tempLen + curLen));
            }
        }

    }
    dest = res,
    len = max;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    table.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        table[a].push_back(Obj(b, c));
        table[b].push_back(Obj(a, c));
        
    }
    int temp, res, len;
    findDis(1, res, len);
    temp = res;
    // cout << "res: " << res << ", len: " << len << endl;
    findDis(temp, res, len);
    int port1 = res, port2;
    findDis(port1, port2, len);

    cout << len << endl;

    return 0;
}
