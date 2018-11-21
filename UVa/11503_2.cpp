#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2

int n;
int parent[100005], count[100005];
char s1[25], s2[25];

typedef struct data
{
	int n;
	char s[25];
}data;

typedef struct node
{
	int n;
	struct data *d1, *d2;
	struct node *left, *center, *right;
}node;

node *head;

data *getdata(char *s, int n)
{
	data *ptr;
	ptr = (data*)malloc(sizeof(data));
	strcpy(ptr->s, s);
	ptr->n = n;
	parent[n] = 0;
	count[n] = 1;
	return ptr;
}

node *getnode(int n, data *d1, data *d2)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	*ptr = (node){n, d1, d2, NULL, NULL, NULL};
	return ptr;
}

node *mergenode(node *ptr, node *tp, int dir)
{
	node *p1, *p2;
	if(tp == NULL)
	{
		return NULL;
	}
	if(ptr->n == 1)
	{
		ptr->n++;
		if(dir == LEFT)
		{
			ptr->d2 = ptr->d1;
			ptr->d1 = tp->d1;
			ptr->right = ptr->center;
			ptr->left = tp->left;
			ptr->center = tp->center;
		}
		else
		{
			ptr->d2 = tp->d1;
			ptr->center = tp->left;
			ptr->right = tp->center;
		}
		return NULL;
	}
	ptr->n = 1;
	if(dir == LEFT)
	{
		p1 = getnode(1, tp->d1, NULL);
		p1->left = tp->left;
		p1->center = tp->center;
		p1->right = NULL;
		p2 = getnode(1, ptr->d2, NULL);
		p2->left = ptr->center;
		p2->center = ptr->right;
		p2->right = NULL;
		ptr->left = p1;
		ptr->center = p2;
	}
	else if(dir == CENTER)
	{
		p1 = getnode(1, ptr->d1, NULL);
		p1->left = ptr->left;
		p1->center = tp->left;
		p1->right = NULL;
		p2 = getnode(1, ptr->d2, NULL);
		p2->left = tp->center;
		p2->center = ptr->right;
		p2->right = NULL;
		ptr->d1 = tp->d1;
		ptr->left = p1;
		ptr->center = p2;
	}
	else
	{
		p1 = getnode(1, ptr->d1, NULL);
		p1->left = ptr->left;
		p1->center = ptr->center;
		p1->right = NULL;
		p2 = getnode(1, tp->d1, NULL);
		p2->left = tp->left;
		p2->center = tp->center;
		p2->right = NULL;
		ptr->d1 = ptr->d2;
		ptr->left = p1;
		ptr->center = p2;
	}
	return ptr;
}

node *search(char *s, int *t, node *ptr)
{
	int d, c1, c2;
	node *tp;
	if(ptr == NULL)
	{
		*t = n;
		return getnode(1, getdata(s, n++), NULL);
	}
	if((c1=strcmp(ptr->d1->s, s)) == 0)
	{
		*t = ptr->d1->n;
		return NULL;
	}
	else if(ptr->n == 2 && (c2=strcmp(ptr->d2->s, s)) == 0)
	{
		*t = ptr->d2->n;
		return NULL;
	}
	d = (c1 > 0) ? LEFT : ((ptr->n == 1 || c2 > 0) ? CENTER : RIGHT);
	if(ptr->left)
	{
		if(c1 > 0)
		{
			tp = search(s, t, ptr->left);
		}
		else if(ptr->n == 1 || c2 > 0)
		{
			tp = search(s, t, ptr->center);
		}
		else
		{
			tp = search(s, t, ptr->right);
		}
	}
	else
	{
		*t = n;
		tp = getnode(1, getdata(s, n++), NULL);
	}
	return mergenode(ptr, tp, d);
}

int getnum(char *s)
{
	int temp;
	node *tp;
	tp = search(s, &temp, head);
	if(head == NULL)
	{
		head = tp;
	}
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
