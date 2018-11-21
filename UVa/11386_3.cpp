#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 500029

int ary[5010];

struct node
{
	int n, c;
	struct node *left, *right;
};

struct node *head;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void insert(struct node *ptr, int target)
{
	if(ptr->n == target)
	{
		ptr->c++;
		return;
	}
	else if(ptr->n > target)
	{
		if(ptr->left)
		{
			insert(ptr->left, target);
			return;
		}
		else
		{
			ptr->left = (struct node*)malloc(sizeof(struct node));
			ptr = ptr->left;
		}
	}
	else
	{
		if(ptr->right)
		{
			insert(ptr->right, target);
			return;
		}
		else
		{
			ptr->right = (struct node*)malloc(sizeof(struct node));
			ptr = ptr->right;
		}
	}
	ptr->n = target;
	ptr->c = 1;
	ptr->left = ptr->right = NULL;
}

int search(struct node *ptr, int target)
{
	if(ptr->n == target)
	{
		return ptr->c;
	}
	else if(ptr->n > target)
	{
		if(ptr->left)
		{
			return search(ptr->left, target);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(ptr->right)
		{
			return search(ptr->right, target);
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

void release(struct node *ptr)
{
	if(ptr->left)
	{
		release(ptr->left);
	}
	if(ptr->right)
	{
		release(ptr->right);
	}
	free(ptr);
}

int main()
{
	int n, i, j, k, l, maximum, ans, index, temp;
	unsigned int sum;
	while(scanf("%d", &n) == 1)
	{
		head = NULL;
		for(i=0, maximum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(head == NULL)
			{
				head = (struct node*)malloc(sizeof(struct node));
				head->n = ary[i];
				head->c = 1;
				head->left = head->right = NULL;
			}
			else
			{
				insert(head, ary[i]);
			}
			if(ary[i] > maximum)
			{
				maximum = ary[i];
			}
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=0, ans=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				sum = (unsigned int)ary[i] + ary[j];
				if(sum > maximum)
				{
					break;
				}
				ans += search(head, sum);
			}
			if(j == i + 1)
			{
				break;
			}
		}
		release(head);
		printf("%d\n", ans);
	}
	return 0;
}
