#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int n;
	node *left, *right;
};

node *head;
char *buf[1000], str[81];
int num;

char push(int i, int j)
{
	node *ptr;
	char s[81], cmp;
	strncpy(s, str+i, j-i+1);
	s[j-i+1] = 0;
	ptr = head;
	if(head == NULL)
	{
		buf[0] = (char*)malloc(j-i+2);
		strcpy(buf[0], s);
		head = (node*)malloc(sizeof(node));
		head -> n = 0;
		head -> left = NULL;
		head -> right = NULL;
		return 1;
	}
	while(1)
	{
		cmp = strcmp(buf[ptr->n], s);
		if(!cmp)
		{
			return 0;
		}
		else if(cmp > 0)
		{
			if(ptr -> left == NULL)
			{
				ptr -> left = (node*)malloc(sizeof(node));
				ptr = ptr -> left;
				buf[num] = (char*)malloc(j-i+2);
				strcpy(buf[num], s);
				ptr -> n = num++;
				ptr -> left = NULL;
				ptr -> right = NULL;
				return 1;
			}
			else
			{
				ptr = ptr -> left;
			}
		}
		else
		{
			if(ptr -> right == NULL)
			{
				ptr -> right = (node*)malloc(sizeof(node));
				ptr = ptr -> right;
				buf[num] = (char*)malloc(j-i+2);
				strcpy(buf[num], s);
				ptr -> n = num++;
				ptr -> left = NULL;
				ptr -> right = NULL;
				return 1;
			}
			else
			{
				ptr = ptr -> right;
			}
		}
	}
}

int check(int i, int j)
{
	int n;
	if(i > j)
	{
		return 1;
	}
	if(str[i] == str[j])
	{
		n = check(i+1, j-1);
		if(n)
		{
			return n + push(i, j);
		}
	}
	return 0;
}

void release(node* now)
{
	if(now == NULL)
	{
		return;
	}
	free(buf[now->n]);
	release(now->left);
	release(now->right);
	free(now);
}

int main()
{
	int n, i, j, ans, tmp;
	while(gets(str))
	{
		if(str[0])
		{
			head = NULL;
			n = strlen(str);
			ans = 0;
			num = 1;
			for(i=0; i<n; i++)
			{
				for(j=i; j<n; j++)
				{
					tmp = check(i, j);
					if(tmp)
					{
						ans += tmp - 1;
					}
				}
			}
			printf("The string '%s' contains %d palindromes.\n", str, ans);
			release(head);
		}
	}
	return 0;
}
