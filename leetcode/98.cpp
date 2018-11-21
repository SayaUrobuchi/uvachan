/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode* root, long long l, long long r)
{
    if (!root)
    {
    	return true;
    }
    if (root->val <= l || root->val >= r)
    {
    	return false;
    }
    if ((root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val))
    {
    	return false;
    }
    return isValid(root->left, l, root->val) && isValid(root->right, root->val, r);
}

bool isValidBST(struct TreeNode* root) {
	return isValid(root, -2147483649LL, 2147483648LL);
}
