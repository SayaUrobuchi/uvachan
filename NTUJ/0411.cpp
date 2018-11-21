#include <stdio.h>

typedef struct abc
{
	int n, p;
	struct abc *left, *right;
}nodd;

nodd nodes[1500000], *node, *head;

void ins(nodd *ptr, int n, int p)
{
	if(p < ptr->p)
	{
		if(ptr->left == NULL)
		{
			ptr->left = node++;
			ptr = ptr->left;
			*ptr = (nodd){n, p, NULL, NULL};
		}
		else
		{
			ins(ptr->left, n, p);
		}
	}
	else
	{
		if(ptr->right == NULL)
		{
			ptr->right = node++;
			ptr = ptr->right;
			*ptr = (nodd){n, p, NULL, NULL};
		}
		else
		{
			ins(ptr->right, n, p);
		}
	}
}

nodd* delmin(nodd* ptr)
{
	if(ptr->left == NULL)
	{
		printf("%d\n", ptr->n);
		return ptr->right;
	}
	ptr->left = delmin(ptr->left);
	return ptr;
}

nodd* delmax(nodd* ptr)
{
	if(ptr->right == NULL)
	{
		printf("%d\n", ptr->n);
		return ptr->left;
	}
	ptr->right = delmax(ptr->right);
	return ptr;
}

int main()
{
	int cmd, n, m;
	head = NULL;
	node = nodes;
	while(scanf("%d", &cmd) == 1)
	{
		if(cmd == 0)
		{
			break;
		}
		else if(cmd == 1)
		{
			scanf("%d%d", &n, &m);
			if(head == NULL)
			{
				head = node++;
				head->n = n;
				head->p = m;
				head->left = head->right = NULL;
			}
			else
			{
				ins(head, n, m);
			}
		}
		else if(cmd == 2)
		{
			if(head == NULL)
			{
				printf("0\n");
			}
			else
			{
				head = delmax(head);
			}
		}
		else if(cmd == 3)
		{
			if(head == NULL)
			{
				printf("0\n");
			}
			else
			{
				head = delmin(head);
			}
		}
	}
	return 0;
}
