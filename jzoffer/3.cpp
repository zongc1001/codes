#include <iostream>
#include <vector>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

using namespace std;
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head != NULL) {
            res.insert(res.begin(), head->val);
            head = head->next;
        
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
