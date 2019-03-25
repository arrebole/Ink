
import java.util.ArrayList;
import java.util.List;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

class Solution {
	List<Integer> results = new ArrayList<Integer>();

	public List<Integer> inorderTraversal(TreeNode root) {
		dfsInorder(root);
		return results;
	}

	private void dfsInorder(TreeNode root) {
		if (root != null) {
			dfsInorder(root.left);
			results.add(root.val);
			dfsInorder(root.right);
		}
	}
}