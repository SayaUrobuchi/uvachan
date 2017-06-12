#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[6];
char buf[2008];
char entext[2008];
char salt[2008];
char word[2008];
char ary[6][2008][6];

struct node
{
	char s[6];
	struct node *left, *right;
};

struct node *head[6];

int uppercase(char *ptr)
{
	if(*ptr >= 'A' && *ptr <= 'Z')
	{
		*ptr -= 32;
		return 1;
	}
	return 0;
}

int lowercase(char *ptr)
{
	return *ptr >= 'a' && *ptr <= 'z';
}

int insert(struct node *ptr, char *s)
{
	int cmp;
	cmp = strcmp(ptr->s, s);
	if(cmp)
	{
		if(cmp > 0)
		{
			if(ptr->left)
			{
				return insert(ptr->left, s);
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
				return insert(ptr->right, s);
			}
			else
			{
				ptr->right = (struct node*)malloc(sizeof(struct node));
				ptr = ptr->right;
			}
		}
		strcpy(ptr->s, s);
		ptr->left = ptr->right = NULL;
		return 1;
	}
	return 0;
}

int add(int len, char *s)
{
	if(head[len])
	{
		return insert(head[len], s);
	}
	else
	{
		head[len] = (struct node*)malloc(sizeof(struct node));
		strcpy(head[len]->s, s);
		head[len]->left = head[len]->right = NULL;
		return 1;
	}
}

int main()
{
	int i, j, k, p, q, len;
	char *ptr, *p2;
	gets(entext);
	sprintf(salt, "%.2s\0", entext);
	while(gets(buf))
	{
		for(ptr=buf, p2=word; ; ptr++)
		{
			if(uppercase(ptr) || lowercase(ptr))
			{
				*(p2++) = *ptr;
			}
			else
			{
				len = p2 - word;
				if(len >= 2 && len <= 5)
				{
					*p2 = 0;
					if(add(len, word))
					{
						strcpy(ary[len][num[len]++], word);
					}
				}
				p2 = word;
				if(!(*ptr))
				{
					break;
				}
			}
		}
	}
	for(p=2, q=5; p<q; p++, q--)
	{
		for(i=0; i<num[p]; i++)
		{
			for(j=0; j<num[q]; j++)
			{
				for(k=0; k<10; k+=2)
				{
					if(k != 6)
					{
						sprintf(buf, "%s%d%s\0", ary[p][i], k, ary[q][j]);
						if(!strcmp(crypt(buf, salt), entext))
						{
							break;
						}
						sprintf(buf, "%s%d%s\0", ary[q][j], k, ary[p][i]);
						if(!strcmp(crypt(buf, salt), entext))
						{
							break;
						}
					}
				}
				if(k < 10)
				{
					break;
				}
			}
			if(j < num[q])
			{
				break;
			}
		}
		if(i < num[p])
		{
			break;
		}
	}
	puts(buf);
	return 0;
}
