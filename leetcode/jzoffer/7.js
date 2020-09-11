	function TreeNode (val) {
		this.val = val
		this.left = this.right = null
	}

	/**
	 * @param {number[]} preorder
	 * @param {number[]} inorder
	 * @return {TreeNode}
	 */
	var buildTree = function (preorder, inorder) {
		// console.log(preorder, inorder);
		if(preorder.length === 0) {
			return null;
		}
		let res = new TreeNode()
		res.val = preorder[0]
		let i = 0
		for (i = 0; inorder[i] !== res.val && i < inorder.length; i++);

		res.left = buildTree(preorder.slice(1, 1 + i), inorder.slice(0, i))
		res.right = buildTree(preorder.slice(1 + i), inorder.slice(i + 1))
		return res;
	}


