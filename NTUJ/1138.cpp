#include <stdio.h>
#include <string.h>

int ver, ans;
char buf[25];

typedef struct node
{
	int cnt, ver, ced;
	struct node *next[26], *prev;
}node;

node pool[3500000], *ptt;

inline node* get()
{
	memset(ptt->next, 0, sizeof(pool[0].next));
	ptt->prev = 0;
	ptt->cnt = 0;
	ptt->ver = 0;
	ptt->ced = 0;
	return ptt++;
}

void build(node *ptr, char *s)
{
	ptr->cnt++;
	if(*s == 0)
	{
		return;
	}
	if(ptr->next[*s-'a'] == 0)
	{
		ptr->next[*s-'a'] = get();
		ptr->next[*s-'a']->prev = ptr;
	}
	build(ptr->next[*s-'a'], s+1);
}

void fill(node *ptr, int num)
{
	if(ptr == 0)
	{
		return;
	}
	fill(ptr->prev, num);
	ptr->ced += num;
}

void travel(node *ptr, char *s, int cos)
{
	int i;
	if(ptr == 0)
	{
		return;
	}
	if(ver != ptr->ver)
	{
		ptr->ver = ver;
		ptr->ced = 0;
	}
	if(*s == 0)
	{
		ans += ptr->cnt-ptr->ced;
		fill(ptr, ptr->cnt-ptr->ced);
		return;
	}
	travel(ptr->next[*s-'a'], s+1, cos);
	if(cos)
	{
		for(i=0; i<26; i++)
		{
			travel(ptr->next[i], s, cos-1);
			travel(ptr->next[i], s+1, cos-1);
		}
		travel(ptr, s+1, cos-1);
	}
}

int main()
{
	int n, i, cos;
	node *head;
	while(scanf("%d", &n) == 1)
	{
		ptt = pool;
		head = get();
		for(i=0; i<n; i++)
		{
			scanf("%s", buf);
			build(head, buf);
		}
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s%d", buf, &cos);
			ans = 0;
			ver = i+1;
			travel(head, buf, cos);
			printf("%d\n", ans);
		}
	}
	return 0;
}
