#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int parent[100005], count[100005];
char s1[25], s2[25];

typedef struct node
{
	int n;
	char s[25];
	struct node *left, *right;
}node;

node *head, nlist[100005];

node *search(char *s, int *t, node *ptr)
{
	int cmp;
	if(ptr == NULL)
	{
		ptr = nlist+n;
		ptr->n = n++;
		strcpy(ptr->s, s);
		ptr->left = ptr->right = NULL;
		*t = ptr->n;
		parent[*t] = 0;
		count[*t] = 1;
		return ptr;
	}
	cmp = strcmp(s, ptr->s);
	if(cmp == 0)
	{
		*t = ptr->n;
	}
	else if(cmp < 0)
	{
		ptr->left = search(s, t, ptr->left);
	}
	else
	{
		ptr->right = search(s, t, ptr->right);
	}
	return ptr;
}

int getnum(char *s)
{
	int temp;
	head = search(s, &temp, head);
	return temp;
}

int getparent(int now)
{
	if(parent[now])
	{
		return parent[now] = getparent(parent[now]);
	}
	return now;
}

void merge(int p, int q)
{
	p = getparent(p);
	q = getparent(q);
	if(p != q)
	{
		parent[p] = q;
		count[q] += count[p];
	}
}

void printans(int targ)
{
	printf("%d\n", count[getparent(targ)]);
}

int main()
{
	int count, m, n1, n2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &m);
		n = 1;
		head = NULL;
		while(m--)
		{
			scanf("%s%s", s1, s2);
			n1 = getnum(s1);
			n2 = getnum(s2);
			merge(n1, n2);
			printans(n1);
		}
	}
	return 0;
}
