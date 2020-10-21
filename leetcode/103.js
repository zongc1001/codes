function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function (root) {
    if(root == null) return [];
    let que = [];
    let res = [];
    que.push(root);
    let toggle = 0;
    while (que.length > 0) {
        res.push(que.map(x => x.val));
        let len = que.length;
        
        toggle ^= 1;
        
        
        let tempQue = [];
        while (len--) {
            let temp = que.pop();
            if (toggle) {
                if (temp.right) {
                    tempQue.push(temp.right);
                }
                if (temp.left) {
                    tempQue.push(temp.left);
                }
            } else {
                if (temp.left) {
                    tempQue.push(temp.left);
                }
                if (temp.right) {
                    tempQue.push(temp.right);
                }
            }
        }
        que = tempQue;
    }
    return res;
};
