#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fl, len;
char final[1005], buf[1005];

struct node
{
	char s[50];
	struct node *left, *right;
};

struct node *head;

void dfs(char*, int);

int compare(char *s1, int l1, char *s2, int l2)
{
	if(l1 > l2)
	{
		return 1;
	}
	else if(l1 < l2)
	{
		return -1;
	}
	else
	{
		return strcmp(s1, s2);
	}
}

int add(struct node *ptr, char *s)
{
	int cmp;
	cmp = strcmp(ptr->s, s);
	if(!cmp)
	{
		return 0;
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			return add(ptr->left, s);
		}
		ptr->left = (struct node*)malloc(sizeof(struct node));
		ptr = ptr->left;
	}
	else
	{
		if(ptr->right)
		{
			return add(ptr->right, s);
		}
		ptr->right = (struct node*)malloc(sizeof(struct node));
		ptr = ptr->right;
	}
	strcpy(ptr->s, s);
	ptr->left = ptr->right = NULL;
	return 1;
}

int insert(char *s)
{
	if(head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		strcpy(head->s, s);
		head->left = head->right = NULL;
		return 1;
	}
	else
	{
		return add(head, s);
	}
}

void dorule1(char *s)
{
	int i, j, remain;
	char b[50];
	i = 0;
	remain = s[0] - '0';
	if(remain < 3 && s[1])
	{
		remain *= 10;
		remain += s[1] - '0';
		i++;
	}
	for(i++, j=1, b[0]=remain/3+'0', remain%=3; s[i]; i++, j++)
	{
		remain *= 10;
		remain += s[i] - '0';
		b[j] = remain / 3 + '0';
		remain %= 3;
	}
	b[j] = 0;
	if(!remain)
	{
		strcpy(s, b);
	}
}

void dorule2(char *s)
{
	int i, j, remain;
	char b[50];
	i = 0;
	remain = s[0] - '0';
	if(remain < 7 && s[1])
	{
		remain *= 10;
		remain += s[1] - '0';
		i++;
	}
	for(i++, j=1, b[0]=remain/7+'0', remain%=7; s[i]; i++, j++)
	{
		remain *= 10;
		remain += s[i] - '0';
		b[j] = remain / 7 + '0';
		remain %= 7;
	}
	b[j] = 0;
	if(!remain)
	{
		strcpy(s, b);
	}
}

int dorule3(char *s, int l)
{
	int i, j, c;
	char b[50];
	for(i=0, c=1; s[i]; i++)
	{
		if(s[i] == '3')
		{
			sprintf(b, "%.*s%s\0", i, s, s+i+1);
			dfs(b, l-1);
			c = 0;
		}
	}
	return c;
}

int dorule4(char *s, int l)
{
	int i, j, c;
	char b[50];
	for(i=0, c=1; s[i]; i++)
	{
		if(s[i] == '7')
		{
			sprintf(b, "%.*s%s\0", i, s, s+i+1);
			dfs(b, l-1);
			c = 0;
		}
	}
	return c;
}

int dorule5(char *s, int l)
{
	int i, j, k, c;
	char b[50];
	for(i=0, k=0, c=1; i+3<=l; i++)
	{
		for(j=1; j<3; j++)
		{
			if(s[i] != s[i+j])
			{
				break;
			}
		}
		if(j == 3)
		{
			sprintf(b, "%.*s%s\0", i, s, s+i+j);
			dfs(b, l-3);
			c = 0;
		}
	}
	return c;
}

int dorule6(char *s, int l)
{
	int i, j, k, c;
	char b[50];
	for(i=0, k=0, c=1; i+7<=l; i++)
	{
		for(j=1; j<7; j++)
		{
			if(s[i] != s[i+j])
			{
				break;
			}
		}
		if(j == 7)
		{
			sprintf(b, "%.*s%s\0", i, s, s+i+j);
			dfs(b, l-7);
			c = 0;
		}
	}
	return c;
}

void dfs(char *s, int l)
{
	char b[30], c;
	/*printf("%s\n", s);*/
	if(compare(s, l, final, fl) < 0)
	{
		return;
	}
	if(!insert(s))
	{
		return;
	}
	if(!l || !strcmp(s, "0"))
	{
		strcpy(final, "0");
		fl = 1;
		return;
	}
	c = 0;
	strcpy(b, s);
	dorule1(b);
	if(strcmp(b, s))
	{
		dfs(b, strlen(b));
		strcpy(b, s);
	}
	else
	{
		c++;
	}
	dorule2(b);
	if(strcmp(b, s))
	{
		dfs(b, strlen(b));
		strcpy(b, s);
	}
	else
	{
		c++;
	}
	c += dorule3(b, l);
	c += dorule4(b, l);
	c += dorule5(b, l);
	c += dorule6(b, l);
	if(c == 6)
	{
		if(!s[0])
		{
			fl = 1;
			strcpy(final, "0");
		}
		else
		{
			fl = l;
			strcpy(final, s);
		}
	}
}

int main()
{
	int count;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", buf);
		len = strlen(buf);
		head = NULL;
		fl = 0;
		final[0] = 0;
		dfs(buf, len);
		printf("%s\n", final);
	}
	return 0;
}
