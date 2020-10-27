
  function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
* @param {TreeNode} root
* @return {boolean}
*/
var isValidBST = function(root) {
  
  if(root === null) return true;
  
  let arr = [];
  (function inOrder(cur) {
      if(cur === null) return;
      else {
          inOrder(cur.left);
          arr.push(cur.val);
          inOrder(cur.right);
      }
  }) (root);
  for(let i = 0; i < arr.length - 1; i++) {
      if(arr[i] >= arr[i + 1]) return false;
  }
  return true;
};




