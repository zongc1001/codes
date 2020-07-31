
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if(!root) return [];
    let res = [];
    let que = [];
    que.push(root);
    while (que.length > 0) {
        let len = que.length;
        res.push([]);
        for (let i = 0; i < len; i++) {
            let t = que.shift();
            res[res.length - 1].push(t.val);
            if (t.left) que.push(t.left);
            if (t.right) que.push(t.right);
        }
        

    }
    return res;
};