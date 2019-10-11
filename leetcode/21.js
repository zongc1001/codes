function ListNode(val) {
    this.val = val;
    this.next = null;
}

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    
    let res;
    if(l1 == null || l2 == null) {
        return l1 == null ? l2 : l1;
    }
    let a, b;
    [a, b] = [l1.val, l2.val];
    res = l1.val < l2.val ? (l1 = l1.next, new ListNode(a))
                          : (l2 = l2.next, new ListNode(b));
    let cur = res;
    while(l1 != null && l2 != null) {
        // console.log('before', l1.val, l2.val);
        let a = l1.val, b = l2.val
        cur.next = a < b ? (l1 = l1.next, new ListNode(a))
                          : (l2 = l2.next, new ListNode(b));
        cur = cur.next
    }
    cur.next = l1 == null ? l2 : l1;
    return res;
};
