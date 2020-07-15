//给出二叉树的后序遍历和中序遍历, 输出层序遍历

#include <cstdio>
#include <queue>
using namespace std;

int n;
int postorder[35];
int inorder[35];

struct period
{
    int begin, end, root;
    period() {}
    period(int begin,
           int end,
           int root)
    :begin(begin), end(end), root(root)
    {   
    }
};

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &postorder[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &inorder[i]);
    }

    queue<period> q;
    q.push(period(1, n, postorder[n]));

    while(!q.empty())
    {
        period& temp = q.front();
        q.push(temp.begin);
    
    }



    return 0;
}
