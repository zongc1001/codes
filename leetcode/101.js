
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */

function is(obj) {
    return obj !== null && obj !== undefined;
}


let equal = function (root1, root2) {
    if (is(root1) && is(root2)) {
        if (root1 !== root2) {
            return false;
        } else {
            return equal(root1.left, root2.right) &&
                equal(root1.right, root2.left);
        }
    } else  {
        return !is(root1) && !is(root2);
    }
}

var isSymmetric = function (root) {
    return equal(root, root);
};


