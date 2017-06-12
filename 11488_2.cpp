#include <stdio.h>

int ans, pp;
char str[205];

typedef struct node
{
	int val;
	struct node *left, *right;
}node;

node *head, pool[10000001];

void add(node *ptr, int dep)
{
	ptr->val += dep;
	if(ptr->val > ans)
	{
		ans = ptr->val;
	}
	if(str[dep] == '0')
	{
		if(ptr->left == NULL)
		{
			ptr->left = &pool[pp++];
			ptr = ptr->left;
			ptr->val = 0;
			ptr->left = ptr->right = NULL;
			add(ptr, dep+1);
		}
		else
		{
			add(ptr->left, dep+1);
		}
	}
	else if(str[dep] == '1')
	{
		if(ptr->right == NULL)
		{
			ptr->right = &pool[pp++];
			ptr = ptr->right;
			ptr->val = 0;
			ptr->left = ptr->right = NULL;
			add(ptr, dep+1);
		}
		else
		{
			add(ptr->right, dep+1);
		}
	}
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		pp = 0;
		head = &pool[pp++];
		head->val = 0;
		head->left = head->right = NULL;
		for(i=0, ans=0; i<n; i++)
		{
			scanf("%s", str);
			add(head, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}
