#include <stdio.h>
#include <string.h>

int par[200005], num[200005], sum[200005], has[200005], ptt;

int getpar(int n)
{
	return par[n]?par[n]=getpar(par[n]):n;
}

int main()
{
	int n, m, i, p, q, t, pp, pv, tar;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(par, 0, sizeof(par));
		memset(num, -1, sizeof(num));
		for(i=1; i<=n; i++)
		{
			has[i] = i;
			sum[i] = i;
		}
		ptt = n+1;
		while(m--)
		{
			scanf("%d", &t);
			if(t == 3)
			{
				scanf("%d", &tar);
				tar = has[tar];
				tar = getpar(tar);
				printf("%d %d\n", -num[tar], sum[tar]);
			}
			else if(t == 2)
			{
				scanf("%d%d", &p, &q);
				pv = p;
				p = has[p];
				q = has[q];
				q = getpar(q);
				pp = getpar(p);
				if(q != pp)
				{
					num[pp]++;
					sum[pp] -= pv;
					num[q]--;
					sum[q] += pv;
					par[ptt] = q;
					has[pv] = ptt++;
				}
			}
			else
			{
				scanf("%d%d", &p, &q);
				p = has[p];
				q = has[q];
				p = getpar(p);
				q = getpar(q);
				if(p != q)
				{
					par[p] = q;
					num[q] += num[p];
					sum[q] += sum[p];
				}
			}
		}
	}
	return 0;
}
