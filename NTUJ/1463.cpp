#include <stdio.h>
#include <string.h>

int sk, qq, pq;
int sn, qt, qh;
int tbl[101], que[1005], stk[1005];

void sk_push(int n)
{
	stk[sn++] = n;
}

void qq_push(int n)
{
	que[qt++] = n;
}

void pq_push(int n)
{
	tbl[n]++;
}

int sk_pop()
{
	if(!sn)
	{
		return -1;
	}
	return stk[--sn];
}

int qq_pop()
{
	if(qh == qt)
	{
		return -1;
	}
	return que[qh++];
}

int pq_pop()
{
	int i;
	for(i=100; i>0&&!tbl[i]; i--);
	tbl[i]--;
	return i;
}

int main()
{
	int n, i, t, m;
	while(scanf("%d", &n) == 1)
	{
		sk = 1;
		sn = 0;
		qq = 1;
		qh = 0;
		qt = 0;
		pq = 1;
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &t, &m);
			if(t == 1)
			{
				sk_push(m);
				qq_push(m);
				pq_push(m);
			}
			else
			{
				if(sk_pop() != m)
				{
					sk = 0;
				}
				if(qq_pop() != m)
				{
					qq = 0;
				}
				if(pq_pop() != m)
				{
					pq = 0;
				}
			}
		}
		if(sk+qq+pq > 1)
		{
			printf("not sure\n");
		}
		else if(sk+qq+pq == 0)
		{
			printf("impossible\n");
		}
		else
		{
			if(sk)
			{
				printf("stack\n");
			}
			else if(qq)
			{
				printf("queue\n");
			}
			else
			{
				printf("priority queue\n");
			}
		}
	}
	return 0;
}
