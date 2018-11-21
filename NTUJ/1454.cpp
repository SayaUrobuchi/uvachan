#include <stdio.h>
#include <string.h>

char s[200005], s2[200005];

typedef struct node
{
	int cnt;
	struct node *c[676];
}node;

node *ptt, pool[100005], *head;

void insert(node *ptr, char *s1, char *s2)
{
	int t;
	ptr->cnt++;
	if(*s1 == 0)
	{
		return;
	}
	t = (*s1-'a') + (*s2-'a')*26;
	if(ptr->c[t] == NULL)
	{
		memset(ptt, 0, sizeof(node));
		ptr->c[t] = ptt++;
	}
	insert(ptr->c[t], s1+1, s2-1);
}

int find(node *ptr, char *s1, char *s2)
{
	int i, r;
	if(ptr == NULL)
	{
		return 0;
	}
	if(!(*s1) && !(*s2))
	{
		return ptr->cnt;
	}
	if(*s1 && *s2)
	{
		return find(ptr->c[(*s1-'a')+(*s2-'a')*26], s1+1, s2+1);
	}
	for(i=0, r=0; i<26; i++)
	{
		if(*s1)
		{
			r += find(ptr->c[*s1-'a'+i*26], s1+1, s2);
		}
		else
		{
			r += find(ptr->c[i+(*s2-'a')*26], s1, s2+1);
		}
	}
	return r;
}

int main()
{
	int n, m, i;
	while(scanf("%d", &n) == 1)
	{
		ptt = pool;
		head = ptt++;
		memset(head, 0, sizeof(node));
		for(i=0; i<n; i++)
		{
			scanf("%s", s);
			insert(head, s, s+strlen(s)-1);
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%s%s", s, s2);
			printf("%d\n", find(head, s, s2));
		}
	}
	return 0;
}
