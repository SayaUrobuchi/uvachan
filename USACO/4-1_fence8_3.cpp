/*
	TASK: fence8
	LANG: C
	ID: sa072682
*/
#include <stdio.h>
#include <stdlib.h>

int n, m, ary[55], rail[1200], sum[1200], waste, allow, id;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int dfsid(int now, int loc)
{
	int i, temp;
	if(now == 0)
	{
		for(i=loc; i<n; i++)
		{
			if(ary[i] >= rail[now])
			{
				return 1;
			}
		}
		return 0;
	}
	for(i=loc; i<n; i++)
	{
		if(ary[i] >= rail[now])
		{
			temp = waste;
			ary[i] -= rail[now];
			if(ary[i] < rail[0])
			{
				waste += ary[i];
			}
			if(waste <= allow)
			{
				if(rail[now-1] == rail[now])
				{
					if(dfsid(now-1, i))
					{
						ary[i] += rail[now];
						return 1;
					}
				}
				else
				{
					if(dfsid(now-1, 0))
					{
						ary[i] += rail[now];
						return 1;
					}
				}
			}
			ary[i] += rail[now];
			waste = temp;
		}
	}
	return 0;
}

int main()
{
	int i, total;
	freopen("fence8.in", "r", stdin);
	freopen("fence8.out", "w", stdout);
	while(scanf("%d", &n) == 1)
	{
		for(i=0, total=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			total += ary[i];
		}
		qsort(ary, n, sizeof(int), comp);
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &rail[i]);
		}
		qsort(rail, m, sizeof(int), comp);
		for(i=0; i<m; i++)
		{
			if(rail[i] > ary[n-1])
			{
				break;
			}
			if(i == 0)
			{
				sum[0] = rail[0];
			}
			else
			{
				sum[i] = sum[i-1] + rail[i];
			}
			if(sum[i] > total)
			{
				break;
			}
		}
		m = i;
		for(id=m-1; id>=0; id--)
		{
			if(total < sum[id])
			{
				continue;
			}
			allow = total - sum[id];
			waste = 0;
			if(dfsid(id, 0))
			{
				break;
			}
		}
		printf("%d\n", id+1);
	}
	return 0;
}
