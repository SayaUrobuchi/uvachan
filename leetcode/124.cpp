/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 int res;
 
 int recurs(struct TreeNode* root)
 {
 	int l, r, t;
 	if (!root)
 	{
 		return 0;
 	}
 	l = recurs(root->left);
 	r = recurs(root->right);
 	if (l+r+root->val > res)
 	{
 		res = l+r+root->val;
 	}
 	t = (l>r ? l : r)+root->val;
 	return t>0 ? t : 0;
 }
 
int maxPathSum(struct TreeNode* root) {
    res = -2147483648LL;
    recurs(root);
    return res;
}
