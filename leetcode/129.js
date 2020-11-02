function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function (root) {
    if (root == null) return 0;
    let que = [];
    que.push(root);
    let res = 0;
    while (que.length > 0) {
        let cur = que.shift();
        if (cur.left) {
            cur.left.val += cur.val * 10;
            que.push(cur.left);
        }
        if (cur.right) {
            cur.right.val += cur.val * 10;
            que.push(cur.right);
        }
        if (!(cur.left || cur.right)) {
            res += cur.val;
        }
    }
    return res;
};
