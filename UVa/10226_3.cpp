#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[100001];
int num[100001];
char species[100001][31];
char str[1000];

struct node
{
	int c;
	struct node *next;
	char name[31];
};

struct node *hash[100001];

int comp(const void *p, const void *q)
{
	return strcmp(species[*(int*)p], species[*(int*)q]);
}

int hashf()
{
	int i, result;
	for(i=0, result=0; str[i]; i++)
	{
		result += str[i] * (i+10);
		result %= 100001;
	}
	return result;
}

void insert(struct node *ptr)
{
	if(!strcmp(ptr->name, str))
	{
		ptr->c++;
		return;
	}
	if(ptr->next)
	{
		insert(ptr->next);
	}
	else
	{
		ptr->next = (struct node*)malloc(sizeof(struct node));
		ptr = ptr->next;
		strcpy(ptr->name, str);
		ptr->c = 1;
		ptr->next = NULL;
	}
}

int main()
{
	int count, n, i, j, temp;
	struct node *ptr;
	scanf("%d", &count);
	gets(str);
	gets(str);
	while(count--)
	{
		memset(hash, 0, sizeof(hash));
		n = 0;
		while(gets(str))
		{
			if(!str[0])
			{
				break;
			}
			temp = hashf();
			if(hash[temp])
			{
				insert(hash[temp]);
			}
			else
			{
				hash[temp] = (struct node*)malloc(sizeof(struct node));
				strcpy(hash[temp]->name, str);
				hash[temp]->c = 1;
				hash[temp]->next = NULL;
			}
			n++;
		}
		for(i=0, j=0; i<100001; i++)
		{
			if(hash[i])
			{
				for(ptr=hash[i]; ptr; ptr=ptr->next)
				{
					index[j] = j;
					strcpy(species[j], ptr->name);
					num[j++] = ptr->c;
				}
			}
		}
		qsort(index, j, sizeof(int), comp);
		for(i=0; i<j; i++)
		{
			printf("%s %.4f\n", species[index[i]], 100.0*num[index[i]]/n);
		}
		if(count)
		{
			putchar(10);
		}
	}
	return 0;
}
