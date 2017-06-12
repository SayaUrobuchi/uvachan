#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tbl[127][11], num[127], c[127], ans;
char str[100];

struct node
{
	char now, flag;
	struct node *child, *right;
};

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

void insert(struct node *ptr, int depth)
{
	if(str[depth] == ptr -> now)
	{
		if(str[depth+1])
		{
			if(ptr -> child == NULL)
			{
				ptr -> child = (struct node*)malloc(sizeof(struct node));
				ptr = ptr -> child;
				ptr -> now = 'a';
				ptr -> flag = 0;
				ptr -> child = ptr -> right = NULL;
			}
			else
			{
				ptr = ptr -> child;
			}
			insert(ptr, depth+1);
		}
		else
		{
			ptr -> flag = 1;
			return;
		}
	}
	else
	{
		if(ptr -> right == NULL || ptr -> right -> now > str[depth])
		{
			ptr -> right = (struct node*)malloc(sizeof(struct node));
			ptr = ptr -> right;
			ptr -> now = str[depth];
			ptr -> flag = 0;
			ptr -> child = ptr -> right = NULL;
		}
		else
		{
			ptr = ptr -> right;
		}
		insert(ptr, depth);
	}
}

void travel(struct node *ptr, int value)
{
	char ch;
	if(ptr -> right)
	{
		travel(ptr->right, value);
	}
	ch = ptr -> now;
	if(c[ch] < num[ch])
	{
		value += tbl[ch][c[ch]++];
		if(ptr->flag && value > ans)
		{
			ans = value;
		}
		if(ptr->child)
		{
			travel(ptr->child, value);
		}
		c[ch]--;
	}
}

int main()
{
	int n, m, in;
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	head -> now = 'a';
	head -> flag = 0;
	head -> child = head -> right = NULL;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", str);
		insert(head, 0);
	}
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &m);
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%s%d", str, &in);
			tbl[str[0]][num[str[0]]++] = in;
			qsort(tbl[str[0]], num[str[0]], sizeof(int), comp);
		}
		memset(c, 0, sizeof(c));
		ans = 0;
		travel(head, 0);
		printf("%d\n", ans);
	}
	return 0;
}
