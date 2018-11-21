#include <stdio.h>
#include <stdlib.h>

int n, now;
int ary[10005];

struct node
{
	int n;
	struct node *left, *right;
};

struct node *head;

struct node *build(int last)
{
	struct node *ptr, *temp;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->n = ary[now++];
	ptr->left = ptr->right = NULL;
	for(; ; )
	{
		if(now == n)
		{
			return ptr;
		}
		if(ary[now] > ary[now-1])
		{
			/*printf("right connection: %d.\n", ptr->n);*/
			ptr -> right = build(ptr->n);
		}
		else
		{
			if(ary[now] > last)
			{
				/*printf("Create a parent: %d.\n", ptr->n);*/
				temp = (struct node*)malloc(sizeof(struct node));
				temp->n = ary[now++];
				temp->left = ptr;
				temp->right = NULL;
				ptr = temp;
			}
			else
			{
				/*printf("RETURN node %d\n", ptr->n);*/
				return ptr;
			}
		}
	}
}

void travel(struct node *ptr)
{
	if(now)
	{
		printf(" ");
	}
	now = 1;
	printf("%d", ptr->n);
	if(ptr->left)
	{
		travel(ptr->left);
	}
	if(ptr->right)
	{
		travel(ptr->right);
	}
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		now = 0;
		head = build(0);
		now = 0;
		travel(head);
		printf("\n");
	}
	return 0;
}
