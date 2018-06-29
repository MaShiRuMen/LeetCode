/*
	104. Maximum Depth of Binary Tree
	Description:
	Given a binary tree,find its maximum depth.
	The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
	
	Note: A leaf is a node with no children.
	
	Example:
		Given a binary tree [3,9,20,null,null,15,7].
				 3
				/ \
			   9  20
				 /  \
				15   7
		return its depth = 3.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int l1, l2, l;
		l = l1 = l2 = 1;
		if ( !root ) return 0;
		if ( root->left ) {	l1 = maxDepth(root->left) + 1;}
		if ( root->right )	{ l2 = maxDepth(root->right) + 1;}
		l = (l1 > l2) ? l1 : l2;
		return l;
    }
};


// another way

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int layer = 0;
		if ( root != NULL ) {
			layer++;
			int layer_l = maxDepth(root->left);
			int layer_r = maxDepth(root->right);
			
			layer += (layer_l > layer_r) ? layer_l : layer_r;
		}
		return layer;
    }
};
