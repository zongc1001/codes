// 试题 算法训练 操作格子
// http://lx.lanqiao.cn/problem.page?gpid=T18
#include <iostream>
#include <cmath>
using namespace std;

struct treeNode
{
    int max;
    int sum;
} segTree[100000 * 4 + 10];

int src[100000 + 10];

/*
root: segTree上的节点的index
arr: 需要处理的数组的地址
begin: 节点所代表区间的begin
end: 节点所代表区间的end
*/
void build(int root, int arr[], int begin, int end)
{
    if (begin == end)
    {
        segTree[root].max = segTree[root].sum = arr[begin];
    }
    else
    {
        int mid = (begin + end) / 2;
        //root * 2就是左孩子的index
        build(root * 2, arr, begin, mid);
        //root * 2 + 1就是右孩子的index   
        build(root * 2 + 1, arr, mid + 1, end);

        // 从子节点返回，回溯更新当前节点
        segTree[root].max = max(segTree[root * 2].max, segTree[root * 2 + 1].max);
        segTree[root].sum = segTree[root * 2].sum + segTree[root * 2 + 1].sum;
    }
}

void updateOne(int root, int begin, int end, int index, int newVal)
{
    if (begin == end)
    {
        if (begin == index)
            segTree[root].max = segTree[root].sum = newVal;
    }
    else
    {
        int mid = (begin + end) / 2;
        if (index <= mid)
            updateOne(root * 2, begin, mid, index, newVal);
        else
            updateOne(root * 2 + 1, mid + 1, end, index, newVal);

        segTree[root].max = max(segTree[root * 2].max, segTree[root * 2 + 1].max);
        segTree[root].sum = segTree[root * 2].sum + segTree[root * 2 + 1].sum;
    }
}

int queryMax(int root, int begin, int end, int qbegin, int qend)
{
    if (begin > qend || qbegin > end)
    {
        return 0;
    }
    else
    {
        if (begin >= qbegin && end <= qend)
        {
            return segTree[root].max;
        }
        else
        {
            int mid = (begin + end) / 2;
            return max(queryMax(root * 2, begin, mid, qbegin, qend),
                       queryMax(root * 2 + 1, mid + 1, end, qbegin, qend));
        }
    }
}

int querySum(int root, int begin, int end, int qbegin, int qend)
{
    // 两区间错开了
    if (begin > qend || qbegin > end)
    {
        return 0;
    }
    // 区间重合
    else
    {
        if (begin >= qbegin && end <= qend)
        {
            return segTree[root].sum;
        }
        else
        {
            int mid = (begin + end) / 2;
            return querySum(root * 2, begin, mid, qbegin, qend) +
                   querySum(root * 2 + 1, mid + 1, end, qbegin, qend);
        }
    }
}

void printtable(int n)
{
    for (int i = 1; i < 4 * n; i++)
    {
        cout << segTree[i].sum << " ";
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> src[i];
    }
    build(1, src, 1, n);

    while (m--)
    {
        int temp, x, y;
        cin >> temp >> x >> y;

        if (temp == 1)
        {
            updateOne(1, 1, n, x, y);
            // printtable(n);
        }
        else if (temp == 2)
        {
            cout << querySum(1, 1, n, x, y) << endl;
        }
        else if (temp == 3)
        {
            cout << queryMax(1, 1, n, x, y) << endl;
        }
    }

    return 0;
}
