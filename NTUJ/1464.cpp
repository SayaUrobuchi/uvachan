#include <stdio.h>

int cnt[200005], par[200005], ptt[200005];
long long sum[200005];

int get_par(int p)
{
	return par[p]?(par[p]=get_par(par[p])):p;
}

int main()
{
	int n, m, i, cmd, p, q, pn, pp, qq;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			cnt[i] = 1;
			par[i] = 0;
			sum[i] = i;
			ptt[i] = i;
		}
		pn = i;
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &cmd, &p);
			if(cmd != 3)
			{
				scanf("%d", &q);
				pp = get_par(ptt[p]);
				qq = get_par(ptt[q]);
				if(pp != qq)
				{
					if(cmd == 1)
					{
						par[pp] = qq;
						cnt[qq] += cnt[pp];
						sum[qq] += sum[pp];
					}
					else
					{
						cnt[pp]--;
						sum[pp] -= p;
						cnt[qq]++;
						sum[qq] += p;
						ptt[p] = pn++;
						par[ptt[p]] = qq;
					}
				}
			}
			else
			{
				p = get_par(ptt[p]);
				printf("%d %lld\n", cnt[p], sum[p]);
			}
		}
	}
	return 0;
}
