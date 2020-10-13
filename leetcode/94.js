function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
  if(root === null) return [];
  let stk = [];
  stk.push(root);
  let cur = root;
  let res = [];
  while(stk.length > 0) {
    while(stk.length > 0 && cur.left !== null) {
      stk.push(cur.left);
      cur = cur.left;
    }
    while(stk.length > 0) {
      cur = stk[stk.length-1];
      res.push(cur.val);
      
      stk.pop();
      if(cur.right !== null) {
        cur = cur.right;
        stk.push(cur);
        break;
      }

    }
  }
  return res;
};