/*
	ID: sa072682
	LANG: C
	TASK: heritage
*/
#include <stdio.h>
#include <stdlib.h>

int c;
char s[30], s2[30], tbl[128];

struct node
{
	char ch;
	struct node *left, *right;
};

void recursion(struct node *ptr, int center, int right)
{
	struct node *temp;
	if(s2[c] && tbl[s2[c]] < center)
	{
		ptr -> left = (struct node*)malloc(sizeof(struct node));
		temp = ptr -> left;
		temp -> ch = s2[c];
		temp -> left = temp -> right = NULL;
		c++;
		recursion(temp, tbl[s2[c-1]], center);
	}
	if(s2[c] && tbl[s2[c]] < right)
	{
		ptr -> right = (struct node*)malloc(sizeof(struct node));
		temp = ptr -> right;
		temp -> ch = s2[c];
		temp -> left = temp -> right = NULL;
		c++;
		recursion(temp, tbl[s2[c-1]], right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr -> left)
	{
		postorder(ptr -> left);
	}
	if(ptr -> right)
	{
		postorder(ptr -> right);
	}
	printf("%c", ptr -> ch);
}

int main()
{
	int n, i;
	struct node *head;
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	scanf("%s%s", s, s2);
	for(i=0; s[i]; i++)
	{
		tbl[s[i]] = i;
	}
	head = (struct node*)malloc(sizeof(struct node));
	head -> ch = s2[0];
	head -> left = head -> right = NULL;
	c = 1;
	recursion(head, tbl[s2[0]], 30);
	postorder(head);
	printf("\n");
	scanf(" ");
	return 0;
}
