var ListNode = /** @class */ (function () {
    function ListNode(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
    return ListNode;
}());
function reverseKGroup(head, k) {
    if (k === 1)
        return head;
    var length = 0;
    var cur = head;
    while (cur !== null) {
        length++;
    }
    function recur(head, k, index) {
        var res = head;
        if (k > length - index) {
            return head;
        }
        else {
            var temp = head;
            for (var i = 0; i < k; i++) {
                temp = temp.next;
            }
            var tempNext = head.next;
            head.next = recur(temp, k, index + k);
            var tempHead = head;
            for (var i = 1; i < k; i++) {
                var a = tempNext.next;
                tempNext.next = tempHead;
                tempHead = tempNext;
                tempNext = a;
            }
            return tempNext;
        }
    }
    return recur(head, k, 0);
}
;
