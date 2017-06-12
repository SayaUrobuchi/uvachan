#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int frequency[5];
char *sequence[5], *tail[5];
char sbuf[5][1000000];
char buf[2008];
char buf2[6];

struct node
{
	char s[6];
	int f;
	struct node *left, *right;
};

struct node *head[5];

struct node *getnode(char *s)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	strcpy(ptr->s, s);
	ptr->f = 1;
	ptr->left = ptr->right = NULL;
	return ptr;
}

int uppercase(char *s)
{
	return *s >= 'A' && *s <= 'Z';
}

int lowercase(char *s)
{
	if(*s >= 'a' && *s <= 'z')
	{
		*s -= 32;
		return 1;
	}
	return 0;
}

void deal(char *s)
{
	char *ptr;
	ptr = s;
	for(; *s; s++)
	{
		if(uppercase(s) || lowercase(s))
		{
			*(ptr++) = *s;
		}
	}
	*ptr = 0;
}

void add(struct node *ptr, char *s)
{
	int cmp;
	cmp = strcmp(ptr->s, s);
	if(!cmp)
	{
		ptr->f++;
		/*printf("%s has FREQUENCY %d\n", ptr->s, ptr->f);*/
	}
	else if(cmp > 0)
	{
		if(ptr->left)
		{
			add(ptr->left, s);
		}
		else
		{
			ptr->left = getnode(s);
		}
	}
	else
	{
		if(ptr->right)
		{
			add(ptr->right, s);
		}
		else
		{
			ptr->right = getnode(s);
		}
	}
}

void insert(int length, char *s)
{
	if(head[length])
	{
		add(head[length], s);
	}
	else
	{
		head[length] = getnode(s);
	}
}

void init()
{
	int i;
	n = 0;
	for(i=0; i<5; i++)
	{
		sequence[i] = sbuf[i];
		sbuf[i][0] = 0;
		tail[i] = sequence[i];
	}
}

void insertion(struct node *ptr)
{
	int i, j;
	char *stemp;
	/*printf("INSERTION %s %d\n", ptr->s, ptr->f);*/
	for(i=n-1; i>=0; i--)
	{
		if(ptr->f < frequency[i])
		{
			break;
		}
		else if(ptr->f == frequency[i])
		{
			sprintf(tail[i], ",%s\0", ptr->s);
			tail[i] += strlen(tail[i]);
			/*printf("SEQUENCE %d INCREASE TO %s\n", frequency[i], sequence[i]);*/
			return;
		}
	}
	if(++i == 5)
	{
		return;
	}
	stemp = sequence[4];
	for(j=4; j>i; j--)
	{
		frequency[j] = frequency[j-1];
		tail[j] = tail[j-1];
		sequence[j] = sequence[j-1];
	}
	sequence[i] = stemp;
	frequency[i] = ptr->f;
	strcpy(sequence[i], ptr->s);
	tail[i] = sequence[i] + strlen(sequence[i]);
	/*printf("CREATE %d %s\n", ptr->f, ptr->s);*/
	if(n < 5)
	{
		n++;
	}
}

void travel(struct node *ptr)
{
	if(ptr->left)
	{
		travel(ptr->left);
	}
	insertion(ptr);
	if(ptr->right)
	{
		travel(ptr->right);
	}
}

int main()
{
	int i, j;
	char *ptr;
	memset(head, 0, sizeof(head));
	while(scanf("%s", buf) == 1)
	{
		deal(buf);
		/*puts(buf);*/
		for(i=0; buf[i]; i++)
		{
			for(j=i, ptr=buf2; buf[j]&&j<i+5; j++)
			{
				*ptr = buf[j];
				*(++ptr) = 0;
				/*puts(buf2);*/
				insert(j-i, buf2);
			}
		}
	}
	for(i=0; i<5; i++)
	{
		if(head[i])
		{
			init();
			travel(head[i]);
			if(n)
			{
				if(i)
				{
					printf("\n");
				}
				printf("Analysis for Letter Sequences of Length %d\n", i+1);
				printf("-----------------------------------------\n");
				for(j=0; j<n; j++)
				{
					printf("Frequency = %d, Sequence(s) = (%s)\n", frequency[j], sequence[j]);
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	for(; ; );
	return 0;
}
