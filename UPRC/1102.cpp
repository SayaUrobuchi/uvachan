#include <stdio.h>
#include <string.h>

int par[50005], cnt[50005];

int get_par(int now)
{
	return ~par[now] ? par[now]=get_par(par[now]) : now;
}

int main()
{
	int n, m, p, q, t, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(par, -1, sizeof(par));
		memset(cnt, -1, sizeof(cnt));
		ans = n-1;
		while(m--)
		{
			scanf("%d%d", &p, &q);
			if((p=get_par(p)) != (q=get_par(q)))
			{
				if(p > q)
				{
					par[p] = q;
					cnt[q] += cnt[p];
					t = q;
				}
				else
				{
					par[q] = p;
					cnt[p] += cnt[q];
					t = p;
				}
				if(cnt[t] < cnt[ans])
				{
					ans = t;
				}
				else if(cnt[t] == cnt[ans] && t > ans)
				{
					ans = t;
				}
			}
		}
		printf("%d\n%d\n", -cnt[ans], ans);
	}
	return 0;
}
