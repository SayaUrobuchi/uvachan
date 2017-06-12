#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c;
char buf[2008], buf2[2008];

struct node
{
	int f;
	char s[1025];
	struct node *left, *right;
};

struct node *head;

struct node *getnode(char *s, int f)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	strcpy(ptr->s, s);
	ptr->f = f;
	ptr->left = ptr->right = NULL;
	return ptr;
}

int lowercase(char *s)
{
	if(*s >= 'a' && *s <= 'z')
	{
		return *s -= 32;
	}
	return 0;
}

int uppercase(char *s)
{
	return *s >= 'A' && *s <= 'Z';
}

void deal(char *s)
{
	char *ptr;
	for(ptr=buf; *s; s++)
	{
		if(uppercase(s) || lowercase(s))
		{
			*(ptr++) = *s;
		}
	}
	*ptr = 0;
}

void add(struct node *ptr, char *s, int f)
{
	int cmp;
	cmp = strcmp(ptr->s, s);
	if(!cmp)
	{
		ptr->f |= f;
		return;
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			add(ptr->left, s, f);
		}
		else
		{
			ptr->left = getnode(s, f);
		}
	}
	else
	{
		if(ptr->right)
		{
			add(ptr->right, s, f);
		}
		else
		{
			ptr->right = getnode(s, f);
		}
	}
}

void insert(int p, int q, int f)
{
	sprintf(buf2, "%.*s", q-p-1, buf+p+1);
	if(head == NULL)
	{
		head = getnode(buf2, f);
	}
	else
	{
		add(head, buf2, f);
	}
}

void travel(struct node *ptr)
{
	if(ptr->left)
	{
		travel(ptr->left);
	}
	if(!(ptr->f))
	{
		if(c)
		{
			printf(" ");
		}
		c = 1;
		printf("%s", ptr->s);
	}
	if(ptr->right)
	{
		travel(ptr->right);
	}
}

int main()
{
	int i, l, p, q;
	while(gets(buf))
	{
		deal(buf);
		head = NULL;
		for(i=0, l=strlen(buf); i<l; i++)
		{
			for(p=i-1, q=i+1; p>=0&&q<l&&buf[p]==buf[q]; insert(p,q,1), p--, q++);
			if(q-p > 2)
			{
				insert(p, q, 0);
			}
			for(p=i, q=i+1; p>=0&&q<l&&buf[p]==buf[q]; insert(p,q,1), p--, q++);
			if(q-p > 3)
			{
				insert(p, q, 0);
			}
		}
		if(head)
		{
			c = 0;
			travel(head);
		}
		printf("\n");
	}
	return 0;
}
