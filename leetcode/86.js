function ListNode(val) {
  this.val = val;
  this.next = null;
}

/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function (head, x) {
  let smaller = new ListNode();
  let sCur = smaller;
  let bigger = new ListNode();
  let bCur = bigger;
  let cur = head;
  while(cur !== null) {
    if(cur.val < x) {
      sCur.next = cur;
      sCur = sCur.next;
    } else {
      bCur.next = cur;
      bCur = bCur.next;
    }
    cur = cur.next;
  }
  sCur.next = bigger.next;
  bCur.next = null;
  return smaller.next;
};