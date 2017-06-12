#include <stdio.h>
#include <stdlib.h>

int a, b;
int ary[100005], idd[100005];
int used[1000005], loc[1000005];

int comp(const void *p, const void *q)
{
	a = *(int*)p;
	b = *(int*)q;
	if(ary[a] == ary[b])
	{
		return a>b ? 1 : -1;
	}
	return ary[a] > ary[b] ? 1 : -1;
}

int main()
{
	int n, m, i, p, q, cnt;
	cnt = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		cnt++;
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idd[i] = i;
		}
		qsort(idd, n, sizeof(idd[0]), comp);
		for(i=0; i<n; i++)
		{
			p = ary[idd[i]];
			if(used[p] != cnt)
			{
				used[p] = cnt;
				loc[p] = i;
			}
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &q, &p);
			--q;
			if(used[p] == cnt && loc[p]+q < n && ary[idd[loc[p]+q]] == p)
			{
				printf("%d\n", idd[loc[p]+q]+1);
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
