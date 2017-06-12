#include <stdio.h>
#include <string.h>

#define STRLEN 2005

int step[10005], n;
char s1[STRLEN], s2[STRLEN], ary[1005][1005], queue[10005][STRLEN];

typedef struct trie
{
	char ch, ans;
	struct trie *left, *right;
}trie;

trie *head, nodes[1000000];

int min(int p, int q)
{
	return p > q ? q : p;
}

char* getdiff(char *p, char *q)
{
	for(; *p&&*q; p++, q++);
	return *p ? p : q;
}

int cmp(char *p, char *q)
{
	for(; *p&&*q; p++, q++)
	{
		if(*p != *q)
		{
			return -1;
		}
	}
	return *p == 0 && *q == 0;
}

int find(trie *ptr, char *p)
{
	if(*p == 0)
	{
		return 0;
	}
	if(ptr == NULL)
	{
		head = nodes + n++;
		head->ch = 0;
		head->ans = 0;
		head->left = NULL;
		head->right = nodes + n++;
		ptr = head->right;
		ptr->ch = *p;
		ptr->ans = 0;
		ptr->left = ptr->right = NULL;
		return find(ptr, p);
	}
	if(*p == ptr->ch)
	{
		if(*(p+1) == 0)
		{
			if(ptr->ans)
			{
				return 1;
			}
			else
			{
				ptr->ans = 1;
				return 0;
			}
		}
		if(ptr->left == NULL)
		{
			ptr->left = nodes + n++;
			ptr = ptr->left;
			ptr->ch = 0;
			ptr->ans = 0;
			ptr->left = ptr->right = NULL;
			return find(ptr, p+1);
		}
		else
		{
			return find(ptr->left, p+1);
		}
	}
	else
	{
		if(ptr->right == NULL)
		{
			ptr->right = nodes + n++;
			ptr = ptr->right;
			ptr->ch = *p;
			ptr->ans = 0;
			ptr->right = ptr->left = NULL;
			return find(ptr, p);
		}
		else
		{
			if((ptr->right)->ch <= *p)
			{
				return find(ptr->right, p);
			}
			else
			{
				(nodes+n)->right = ptr->right;
				ptr->right = nodes + n++;
				ptr = ptr->right;
				ptr->ch = *p;
				ptr->ans = 0;
				ptr->left = NULL;
				return find(ptr, p);
			}
		}
	}
}

int main()
{
	int count, m, i, j, k, s, c;
	char *p, *q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s%d", s1, s2, &m);
		head = NULL;
		n = 0;
		for(i=0; i<m; i++)
		{
			scanf("%s", ary[i]);
		}
		if(strcmp(s1, s2) == 0)
		{
			printf("0\n");
		}
		else if(strncmp(s1, s2, min(strlen(s1), strlen(s2))))
		{
			printf("-1\n");
		}
		else
		{
			strcpy(queue[0], p=getdiff(s1, s2));
			find(head, p);
			step[0] = 0;
			for(i=0, j=1; i<j; i++)
			{
				q = queue[i];
				s = step[i] + 1;
				for(k=0; k<m; k++)
				{
					if((c=cmp(q, ary[k])) == 0)
					{
						if(find(head, p=getdiff(q, ary[k])) == 0)
						{
							strcpy(queue[j], p);
							step[j++] = s;
						}
					}
					else if(c == 1)
					{
						break;
					}
				}
				if(k < m)
				{
					break;
				}
			}
			if(i == j)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", s);
			}
		}
	}
	return 0;
}
