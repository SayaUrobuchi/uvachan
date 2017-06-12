#include <stdio.h>
#include <string.h>

int par[100005], tbl[128];
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
		memset(tbl, 0, sizeof(tbl));
		ans = m+1;
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
				par[b] = a;
				ans--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
