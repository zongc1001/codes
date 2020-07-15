#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode
{
    int id;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int i = 0, TreeNode *l = NULL, TreeNode *r = NULL)
        : id(i), left(l), right(r)
    {
    }
};

TreeNode *arr[100];

void printRes(TreeNode *r)
{
    queue<TreeNode *> q;
    q.push(r);
    TreeNode *cur = r;
    while (cur->right != NULL)
    {
        q.push(cur->right);
        cur = cur->right;
        // cout << "here";
    }
    cur = r;
    bool isFirstLoop = true;
    while (!q.empty())
    {
        // cout << "here1";

        int numOfRes = 0; //每层没有后代的节点
        queue<TreeNode *> qq;
        while (!q.empty())
        {
            // cout << "here2";

            qq.push(q.front());
            q.pop();
        }
        while (!qq.empty())
        {
            // cout << "here3";

            TreeNode *temp = qq.front();
            qq.pop();
            if (temp->left == NULL)
            {
                numOfRes++;
            }
            else
            {
                q.push(temp->left);
                TreeNode *child1 = temp->left;
                while (child1->right != NULL)
                {
                    q.push(child1->right);
                    child1 = child1->right;
                }
            }
        }
        if (isFirstLoop)
        {
            isFirstLoop = false;
            cout << numOfRes;
        }
        else
        {
            cout << " " << numOfRes;
        }
    }
    cout << endl;
}
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    for (int i = 1; i <= 99; i++)
    {
        arr[i] = new TreeNode();
    }
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> m;
        for (int i = 1; i <= 99; i++)
        {
            arr[i]->left = arr[i]->right = NULL;
        }
        while (m--)
        {
            int tempPar;
            int k;
            cin >> tempPar >> k;
            if (k <= 0)
                continue;
            int firstChild;
            cin >> firstChild;
            arr[tempPar]->left = arr[firstChild];
            TreeNode *lastNode = arr[firstChild];
            for (int i = 1; i < k; i++)
            {
                int temp;
                cin >> temp;
                lastNode->right = arr[temp];
                lastNode = arr[temp];
            }
        }
        printRes(arr[1]);
        //
    }
    return 0;
}
