/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
	struct TreeNode *ptr, **par, **par2;
	par = &root;
	ptr = root;
	while (ptr && ptr->val != key)
	{
		if (ptr->val > key)
		{
			par = &(ptr->left);
			ptr = ptr->left;
		}
		else
		{
			par = &(ptr->right);
			ptr = ptr->right;
		}
	}
	if (!ptr)
	{
		return root;
	}
	if (!(ptr->left))
	{
		*par = ptr->right;
	}
	else if (!(ptr->right))
	{
		*par = ptr->left;
	}
	else
	{
		par2 = &(ptr->left);
		while ((*par2)->right)
		{
			par2 = &((*par2)->right);
		}
		(*par)->val = (*par2)->val;
		(*par2) = (*par2)->left;
	}
	return root;
}
