function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
    if (head === null || head.next === null) {
        return head;
    }
    
    let list = [];
    let cur = head;
    let res = head.next;
    while (cur !== null) {
        list.push(cur);
        cur = cur.next;
    }
    let len = list.length;
    list.forEach((x, i) => {
        if (i & 1) {
            x.next = list[i - 1];
        } else {
            if (i + 3 < len) {
                x.next = list[i + 3];
            } else if (i + 2 < len) {
                x.next = list[i + 2];
            } else {
                x.next = null;
            }
        }
    })
    return res;
};