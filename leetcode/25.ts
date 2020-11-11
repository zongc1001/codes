
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    if (k === 1) return head;
    let length: number = 0;
    let cur = head;
    while (cur !== null) {
        length++;
    }

    function recur(head: ListNode, k: number, index: number): ListNode {
        console.log(head, k, index)
        if (k > length - index) {
            return head;
        } else {
            let temp: ListNode = head;
            for (let i = 0; i < k; i++) {
                if (temp.next) {
                    temp = temp.next;
                }
            }
            let tempNext: ListNode = head;
            if (head.next) {
                tempNext = head.next;
            }
            
            head.next = recur(temp, k, index + k);
            console.log(head.next)
            let tempHead: ListNode = head;
            for (let i = 1; i < k; i++) {
                let a: any;
                if (tempNext.next) {
                    a = tempNext.next;
                }

                tempNext.next = tempHead;
                tempHead = tempNext;
                tempNext = a;
            }
            return tempNext;
        }
    }
    if (head) {
        return recur(head, k, 0);
    } else {
        return null;
    }
};
