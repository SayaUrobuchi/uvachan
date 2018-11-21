#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum;
char str[31];

struct node
{
	struct node *left, *right;
	int c;
	char s[31];
};

void insert(struct node *ptr)
{
	int cmp;
	cmp = strcmp(ptr->s, str);
	if(!cmp)
	{
		ptr->c++;
		return;
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			insert(ptr->left);
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
			insert(ptr->right);
			return;
		}
		else
		{
			ptr->right = (struct node*)malloc(sizeof(struct node));
			ptr = ptr->right;
		}
	}
	strcpy(ptr->s, str);
	ptr->c = 1;
	ptr->left = ptr->right = NULL;
}

void travel(struct node *ptr)
{
	if(ptr->left)
	{
		travel(ptr->left);
	}
	printf("%s %.4lf\n", ptr->s, 100.0*ptr->c/sum);
	if(ptr->right)
	{
		travel(ptr->right);
	}
	free(ptr);
}

int main()
{
	int count;
	struct node *head;
	scanf("%d", &count);
	gets(str);
	gets(str);
	while(count--)
	{
		gets(str);
		head = (struct node*)malloc(sizeof(struct node));
		strcpy(head->s, str);
		head->c = 1;
		head->left = head->right = NULL;
		sum = 1;
		while(gets(str))
		{
			if(!str[0])
			{
				break;
			}
			insert(head);
			sum++;
		}
		travel(head);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
