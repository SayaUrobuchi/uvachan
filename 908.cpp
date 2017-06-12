#include <stdio.h>
#include <stdlib.h>

int ary[1000000][3], node[1000000];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int parent(int now)
{
	if(node[now] == -1)
	{
		return now;
	}
	return node[now] = parent(node[now]);
}

int main()
{
	int cas, n, m, i, p, q, r, ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(cas)
		{
			putchar('\n');
		}
		cas = 1;
		node[n] = -1;
		for(i=1, ans=0; i<n; i++)
		{
			node[i] = -1;
			scanf("%d%d%d", &p, &q, &r);
			ans += r;
		}
		printf("%d\n", ans);
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &ary[i][1], &ary[i][2], &ary[i][0]);
		}
		scanf("%d", &r);
		m += r;
		for(; i<m; i++)
		{
			scanf("%d%d%d", &ary[i][1], &ary[i][2], &ary[i][0]);
		}
		qsort(ary, m, sizeof(ary[0]), comp);
		for(i=0, ans=0; i<m; i++)
		{
			p = ary[i][1];
			q = ary[i][2];
			r = ary[i][0];
			if(parent(p) != parent(q))
			{
				node[parent(q)] = parent(p);
				ans += r;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
