/*
问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？

输入格式
第一行包含一个整数 n 。

接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。

接下来一共 n-1 行，每行描述树上的一条边。

输出格式
输出一个整数，代表选出的点的权值和的最大值。
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct TreeNode
{
    unsigned long value;
    vector<int> childs;
    TreeNode(unsigned long v)
    {
        value = v;
        // childs = vector<TreeNode*>();
    }
};

TreeNode *nodes[100000 + 10];
bool visited[100000 + 10];

int n;

vector<vector<int> > joint;

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        nodes[i] = new TreeNode(temp);
    }
    joint.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        joint[a].push_back(b);
        joint[b].push_back(a);
    }

    int cur;
    queue<int> que;
    que.push(1);
    visited[1] = true;
    while (!que.empty())
    {
        cur = que.front();
        que.pop();
        cout << cur <<endl;
        for (int i = 0; i < joint[cur].size(); i++)
        {
            int temp = joint[cur][i];
            if (!visited[temp])
            {
                visited[temp] = true;
                que.push(temp);
                nodes[cur]->childs.push_back(temp);

            }
        }
    }

    queue<TreeNode*> q;
    q.push(nodes[1]);
    while(!q.empty())
    {
        cout << q.front()->value << " ";
        for(int i = 0; i  < q.front()->childs.size(); i++)
        {
            q.push(nodes[q.front()->childs[i]]);
        }
        q.pop();

    }

    return 0;
}
