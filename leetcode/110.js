function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isBalanced = function (root) {
  if (root === null) {
    return true;
  }
  /**
   * 
   * @param {TreeNode} root 
   * @return {Number} 
   */
  function height(root) {
    if (root == null) return 0;
    else {
      let left = height(root.left);
      // console.log("left", root.val, left);
      if (left === -1) return -1;
      let right = height(root.right);
      // console.log("right", root.val, right);

      if (right === -1) return -1;

      // console.log(left, right, Math.abs(left - right));
      if (Math.abs(left - right) > 1) return -1;
      else return Math.max(left, right) + 1;
    }
  }
  return height(root) >= 0;
};
