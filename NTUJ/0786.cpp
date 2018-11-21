#include <stdio.h>

int c, pt;

typedef struct node
{
	int val;
	struct node *left, *right;
}node;

node pool[1000000], *head;

node *insert(node *ptr, int t)
{
	if(ptr == NULL)
	{
		ptr = pool+pt++;
		ptr->val = t;
		ptr->left = ptr->right = NULL;
		return ptr;
	}
	c++;
	if(t < ptr->val)
	{
		ptr->left = insert(ptr->left, t);
	}
	else
	{
		ptr->right = insert(ptr->right, t);
	}
	return ptr;
}

int main()
{
	int n, i, t;
	while(scanf("%d", &n) == 1)
	{
		c = 0;
		head = NULL;
		for(i=0; i<n; i++)
		{
			scanf("%d", &t);
			head = insert(head, t);
			printf("%d\n", c);
		}
	}
	return 0;
}
