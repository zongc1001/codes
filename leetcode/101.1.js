
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */


var isSymmetric = function (root) {
    if(!root) return true;
    let que1 = [], l = root;
    let que2 = [], r = root;
    que1.push(root);
    que2.push(root);
    while (que1.length > 0 && que2.length > 0) {
        // console.log(l, r);
        
        if (l && r) {
            
            if (l.val !== r.val) {
                return false;
            }
            que1.push(l);
            que2.push(r);
            l = l.left;
            r = r.right;
        } else if (!l && !r) {
            if (que1.length > 0 && que2.length > 0) {
                l = que1.pop();
                r = que2.pop();
                l = l.right;
                r = r.left;
            }
        } else {
            return false;
        }


    }

    return true;

};


