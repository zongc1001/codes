#include <iostream>
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* res = pListHead;
        ListNode* cur = pListHead;
        int t = k - 1;
        if(cur == NULL || k == 0) return NULL;
        while(cur->next != NULL && t > 0) {
            cur = cur->next;
            t--;
        }
        if(t > 0) return NULL;
        while(cur->next != NULL) {
            res = res->next;
            cur = cur->next;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int t = 10;
    while(--t);
    cout << t;
    return 0;
}
