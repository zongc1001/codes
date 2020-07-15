//http://lx.lanqiao.cn/problem.page?gpid=T34

#include <cstdio>
#include <stack>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;        
    int deep;           //结点的深度, 等于在输出结果中前面的字符的数量
    int numOfDigit;     //val的位数, 用以计算其他结点前的空格的数量
    int printOrder;     //表示在第几行被打印, 同时也是遍历时的顺序
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int v = 0, int d = 0, int n = 1, TreeNode *l = NULL, TreeNode *r = NULL)
        : val(v), left(l), right(r), deep(d), numOfDigit(n)
    {
        while (v /= 10)
        {
            numOfDigit++;
        }
        printOrder = 0;
    }
};

TreeNode *printArr[105];    
int treeIndex = 0;          //printArr的下标
int maxDeep = 0;            //最大可能的深度
int maxDigit = 0;           //最大的位数, 与最大深度一起计算出最大可能的一行的字符数
TreeNode *root;             //根节点指针
/*
对数组进行第一遍处理
*/
void printTree(TreeNode *cur)
{
    if (cur != NULL)
    {
        printTree(cur->right);
        if (cur->deep > maxDeep)
            maxDeep = cur->deep;
        if (cur->numOfDigit > maxDigit)
            maxDigit = cur->numOfDigit;
        cur->printOrder = treeIndex;

        printArr[treeIndex++] = cur;

        printTree(cur->left);
    }
}

/*
最后补全输出的字符表
*/
void completeRes(TreeNode *cur, vector<string> &vec)
{
    if (cur != NULL)
    {
        completeRes(cur->right, vec);
        string &temp = vec[cur->printOrder];
        if (cur != root)
        {
            temp[cur->deep - 1] = '-';
        }
        if (!(cur->left == NULL && cur->right == NULL))
        {
            temp.push_back('-');
            temp.push_back('|');
        }
        int pos = vec[cur->printOrder].size() - 1;
        // printf("pos: %d\n", pos);

        if (cur->left != NULL)
        {
            for (int i = cur->printOrder + 1; i < treeIndex; i++)
            {
                vec[i][pos] = '|';
                if (printArr[i]->val == cur->left->val)
                    break;
            }
        }
        if (cur->right != NULL)
        {
            // printf("cur->printOrder - 1: %d\n", cur->printOrder - 1);
            for (int i = cur->printOrder - 1; i >= 0; i--)
            {
                vec[i][pos] = '|';
                if (printArr[i]->val == cur->right->val)
                    break;
            }
        }
        // printf("%s\n", temp.c_str());
        completeRes(cur->left, vec);
    }
}

int main(int argc, char const *argv[])
{
    int temp;
    // FILE *fp;
    // fp = fopen("11.txt", "r");
    // fscanf(fp, "%d", &temp);
    scanf("%d", &temp);
    root = new TreeNode(temp);
    while (scanf("%d", &temp) != EOF)
    {
        TreeNode *tempRoot = root;
        //tempdeep 用于计算深度
        int tempdeep = tempRoot->numOfDigit + 3;
        while (true)
        {
            if (temp > tempRoot->val)
            {
                if (tempRoot->right != NULL)
                {
                    tempRoot = tempRoot->right;
                    tempdeep += tempRoot->numOfDigit + 3;
                }
                else
                {
                    tempRoot->right = new TreeNode(temp, tempdeep);
                    // printf("temp: %d, tempdeep: %d\n", temp, tempdeep);
                    break;
                }
            }
            else
            {
                if (tempRoot->left != NULL)
                {
                    tempRoot = tempRoot->left;
                    tempdeep += tempRoot->numOfDigit + 3;
                }
                else
                {
                    tempRoot->left = new TreeNode(temp, tempdeep);
                    // printf("temp: %d, tempdeep: %d\n", temp, tempdeep);
                    break;
                }
            }
        }
    }
    printTree(root);
    vector<string> res;
    for (int i = 0; i < treeIndex; i++)
    {
        string temp;
        for (int j = 0; j < printArr[i]->deep; j++)
        {
            temp += ".";
        }
        char num[10];
        sprintf(num, "%d", printArr[i]->val);
        temp += num;
        // printf("%s\n", temp.c_str());
        res.push_back(temp);
    }
    completeRes(root, res);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str());
    }

    return 0;
}
