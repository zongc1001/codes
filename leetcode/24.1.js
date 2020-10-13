/**
 * Definition for singly-linked list.
 *
 */
function ListNode (val) {
  this.val = val
  this.next = null
}
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
  let cur = head;
  if(cur === null || cur.next === null) return;
  let res = head.next;
  while (cur !== null && cur.next !== null) {
    let temp = cur.next;
    cur.next = temp.next;
    temp.next = cur;
    cur = cur.next;
  }
  return res;
}



