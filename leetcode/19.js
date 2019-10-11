function ListNode(val) {
   this.val = val;
   this.next = null;
}
 
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let arr = new Array();
    let cur = head;
    while(cur !== null) {
        arr.push(cur);
        if(arr.length > n+1) arr.shift();
        cur = cur.next;
    }
    let len = arr.length;
    
    if(len === n) {
        head = arr[0].next;
    } else if (len > n) {
        arr[0].next = arr[0].next.next;
    }

    return head;
     

};


// console.log(removeNthFromEnd([1,2,3,4,5], 2));