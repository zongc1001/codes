function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var oddEvenList = function (head) {
    let oddHead = new ListNode();
    let evenHead = new ListNode();
    let oddCur = oddHead;
    let evenCur = evenHead;
    
    let cur = head;
    let toggle = true;
    while(cur !== null) {
        if(toggle) {
            oddCur.next = cur;
            oddCur = cur;
        } else {
            evenCur.next = cur;
            evenCur = cur;
        }
        cur = cur.next;
        toggle = !toggle;
    }
    evenCur.next = null;
    oddCur.next = evenHead.next;

    return oddHead.next;
};