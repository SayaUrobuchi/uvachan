#include <stdio.h>

int loc, hash[128];
char *ptr, s1[100], s2[100], s[100];

typedef struct tree
{
	struct tree *left, *right;
	char value;
}tree;

tree *head, node[100];

void recursion(tree* p, int left, int right)
{
	int center;
	if(*ptr == 0)
	{
		return;
	}
	tree *t;
	center = hash[p->value];
	if(hash[*ptr] < center)
	{
		p->left = node+loc++;
		t = p->left;
		t->value = *(ptr++);
		t->left = t->right = NULL;
		recursion(t, left, center-1);
	}
	if(*ptr == 0)
	{
		return;
	}
	if(hash[*ptr] <= right)
	{
		p->right = node+loc++;
		t = p->right;
		t->value = *(ptr++);
		t->left = t->right = NULL;
		recursion(t, center+1, right);
	}
}

void travel(tree* p)
{
	if(p->left)
	{
		travel(p->left);
	}
	if(p->right)
	{
		travel(p->right);
	}
	*(ptr++) = p->value;
}

int main()
{
	int i;
	while(scanf("%s%s", s1, s2) == 2)
	{
		for(i=0; s2[i]; i++)
		{
			hash[s2[i]] = i;
		}
		loc = 0;
		head = node+loc++;
		head->value = s1[0];
		head->left = head->right = NULL;
		ptr = s1+1;
		recursion(head, 0, i-1);
		ptr = s;
		travel(head);
		*ptr = 0;
		printf("%s\n", s);
	}
	return 0;
}
