function ListNode (val) {
  this.val = val
  this.next = null
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function (head) {
  let cur = head
  if (cur === null || cur.next === null) return cur
  while (cur !== null) {
    while (cur.next !== null && cur.val === cur.next.val) {
      let temp = cur.next;
      cur.next = temp.next;
    }
    cur = cur.next;
  }
  return head;
}

function ZCLOVEXH(params) {
  
}

// const ZCLOVEXH = true
// setInterval(ZCLOVEXH, 1);
for(;;) {

}


