#include <stdio.h>
#include <string.h>

int par[100005], edg[100005], cnt[100005], tbl[128];
char b0[10005], b1[10005];

int find(int t)
{
	if(par[t] == 0)
	{
		return t;
	}
	return par[t]=find(par[t]);
}

int main()
{
	int n, m, c, i, a, b, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(m == 0)
		{
			printf("1\n");
			continue;
		}
		c = 1;
		memset(par, 0, sizeof(par));
		memset(edg, 0, sizeof(edg));
		memset(cnt, -1, sizeof(cnt));
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<m; i++)
		{
			scanf("%s%s", b0, b1);
			if(!tbl[*b0])
			{
				tbl[*b0] = c++;
			}
			if(!tbl[*b1])
			{
				tbl[*b1] = c++;
			}
			a = find(tbl[*b0]);
			b = find(tbl[*b1]);
			if(a != b)
			{
				cnt[a] += cnt[b];
				edg[a] += edg[b];
				par[b] = a;
			}
			edg[a]++;
		}
		ans = 1;
		for(i=1; i<=c; i++)
		{
			if(par[i] == 0)
			{
				ans += edg[i] + cnt[i] + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
