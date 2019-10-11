#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        
        // TreeNode r(pre[0]);
        TreeNode* root = new TreeNode(pre[0]);
        int i;
        for(i = 0; i < vin.size();i++) {
            if(vin[i] == pre[0])
                break;
        }
        root->left = reConstructBinaryTree(vector<int>(pre.begin() + 1, pre.begin() + i + 1),
                                           vector<int>(vin.begin(), vin.begin() + i));
        root->right = reConstructBinaryTree(vector<int>(pre.begin() + 1 + i, pre.end()),
                                           vector<int>(vin.begin()+ i+ 1, vin.end()));
        return root;

    }
};

void printTreeInPost(TreeNode* t) {
    if(t!=NULL) {
        printTreeInPost(t->left);
        printTreeInPost(t->right);
        cout << t->val;
        
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> v1;
    int a1[] = {1,2,3,4,5,6,7};
    vector<int> v2;
    int a2[] = {3,2,4,1,6,5,7};
    for(int i = 0; i < 7;i++) {
        v1.push_back(a1[i]);
        v2.push_back(a2[i]);
    }
    Solution s;
    TreeNode* t = s.reConstructBinaryTree(v1,v2);
    // cout << t->val;    
    printTreeInPost(t);

    return 0;
}
