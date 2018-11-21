#include <stdio.h>
#include <string.h>

int ans;
char str[55], *q;

typedef struct tree
{
	char s[55], ans;
	struct tree *left, *right;
}tree;

tree node[100000], *head, *p;

int find(tree *ptr, char *s)
{
	int cmp;
	if((cmp=strcmp(ptr->s, s)) == 0)
	{
		return ptr->ans;
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			return find(ptr->left, s);
		}
		ptr->left = p++;
		ptr = ptr->left;
		strcpy(ptr->s, s);
		ptr->left = ptr->right = NULL;
		q = &(ptr->ans);
		return -1;
	}
	else
	{
		if(ptr->right)
		{
			return find(ptr->right, s);
		}
		ptr->right = p++;
		ptr = ptr->right;
		strcpy(ptr->s, s);
		ptr->left = ptr->right = NULL;
		q = &(ptr->ans);
		return -1;
	}
}

int recursion(char* s, int times)
{
	int i, j, res;
	char ts[55], *temp;
	for(j=strlen(s)-1; j>=0&&s[j]=='B'; j--, times++);
	s[++j] = 0;
	/*printf("%s\n", s);*/
	if((res=find(head, s)) != -1)
	{
		if(res == 1)
		{
			ans = times;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	temp = q;
	for(i=0; s[i]; i++)
	{
		if(s[i] == 'B' && (i == 0 || s[i-1] != 'B'))
		{
			sprintf(ts, "%s%.*s\0", s+i+1, i, s);
			if(recursion(ts, times+1))
			{
				return *temp=1;
			}
		}
	}
	return *temp=0;
}

int main()
{
	p = node;
	head = p++;
	strcpy(head->s, "BlackToAttack");
	head->ans = 1;
	head->left = head->right = NULL;
	while(gets(str))
	{
		if(recursion(str, 0))
		{
			printf("YES\n%d\n", ans);
		}
		else
		{
			printf("NO\n0\n");
		}
	}
	return 0;
}
