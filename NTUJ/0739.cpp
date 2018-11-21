#include <stdio.h>
#include <string.h>

int par[1000005], cnt[1000005], top[1000005], hash[1000005], list[1000005];
char buf[1000005];

int find_parent(int p)
{
	int t;
	if(par[p] == 0)
	{
		return p;
	}
	t = par[p];
	par[p] = find_parent(par[p]);
	top[p] += top[t];
	return par[p];
}

int main()
{
	int n, i, p, q, pp, qq, cc;
	cc = 0;
	memset(cnt, -1, sizeof(cnt));
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<cc; i++)
		{
			cnt[list[i]] = -1;
			par[list[i]] = 0;
			top[list[i]] = 0;
			hash[list[i]] = 0;
		}
		cc = 0;
		for(i=0; i<n; i++)
		{
			scanf("%s", buf);
			if(*buf == 'M')
			{
				scanf("%d%d", &p, &q);
				pp=find_parent(p);
				qq=find_parent(q);
				top[qq] = cnt[pp];
				cnt[pp] += cnt[qq];
				par[qq] = pp;
				if(hash[p] == 0)
				{
					hash[p] = 1;
					list[cc++] = p;
				}
				if(hash[q] == 0)
				{
					hash[q] = 1;
					list[cc++] = q;
				}
			}
			else
			{
				scanf("%d", &p);
				pp = find_parent(p);
				printf("%d\n", -cnt[pp]+top[p]-1);
			}
		}
	}
	return 0;
}
