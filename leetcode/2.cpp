#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        bool carry = false;

        while (l1 != NULL || l2 != NULL || carry)
        {
            int a1 = l1 == NULL ? 0 : l1->val;
            int a2 = l2 == NULL ? 0 : l2->val;
            int temp = a1 + a2 + carry;
            // cout << carry << endl;
            carry = false;
            if(temp >= 10) {
                carry = true;
                temp -= 10;
            }
            cur->val = temp;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            if(l1 != NULL || l2 != NULL || carry ) {
                cur->next = new ListNode(0);
                cur = cur->next;
            
            }
            
        }
        
        return res;


    }
};
