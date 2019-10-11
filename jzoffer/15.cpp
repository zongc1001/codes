#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;
        stack<ListNode*> s;
        while(pHead != NULL) {
            s.push(pHead);
            pHead = pHead->next;
        }
        ListNode* res = s.top();
        ListNode* cur = s.top();
        s.pop();
        while(!s.empty()) {

            cur->next = s.top();
            s.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 10;
    ListNode* node[n];

    for(int i = 0; i < n; i++) {
        node[i] = new ListNode(i);
    }
    for(int i = 0;i < n-1;i++) {
        node[i]->next = node[i+1];
    }
    // ListNode* t = node[0];

    // while(t != NULL) {
    //     cout << t->val;
    //     t = t->next;
    // }
    Solution s;

    ListNode* temp = s.ReverseList(node[0]);

    // cout << temp->val;
    while(temp != NULL) {
        cout << temp->val;
        temp = temp->next;
    }
    return 0;
}
