#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        // stack<TreeNode *> s;
        stack<pair<TreeNode *, int>> s;
        int max = 0;
        int curDeep = 0;
        TreeNode *cur = root;
        // TreeNode *cur = root;
        while (!s.empty() || cur != NULL)
        {
            while (cur != NULL)
            {
                // max = max > cur ? max : cur.second;
                s.push(pair<TreeNode *, int>(cur, ++curDeep));
                cur = cur->left;
            }
            cur = s.top().first;
            curDeep = s.top().second;
            if(max < curDeep) max = curDeep;
            s.pop();
            cur = cur->right;
        }

        return max;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int Maxdeep=0;
        int deep=0;
        while(!s.empty()||p!=NULL)//若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
        {
            while(p!=NULL)//优先往左边走
            {
                s.push(pair<TreeNode*,int>(p,++deep));
                p=p->left;
            }
            p=s.top().first;//若左边无路，就预备右拐。右拐之前，记录右拐点的基本信息
            deep=s.top().second;
            if(Maxdeep<deep) Maxdeep=deep;//预备右拐时，比较当前节点深度和之前存储的最大深度
            s.pop();//将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
            p=p->right;
        }
        return Maxdeep;

    }
};

int main(int argc, char const *argv[])
{
    Solution a;

    return 0;
}
