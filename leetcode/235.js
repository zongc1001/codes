function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}


/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    let cur = root;
    if(p.val > q.val) {
        [p, q] = [q, p];
    }
    while(!(cur.val >= p.val && cur.val <= q.val)) {
        if(cur.val < p.val) {
            cur = cur.right;
        } else {
            cur = cur.left;
        }
    }
    return cur;
};
