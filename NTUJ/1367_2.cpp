#include <stdio.h>
#include <string.h>

int cir[1005], gg[1005], tbl[1005][1005];
long long tree[1005][1005], pos[1005][1005], neg[1005][1005];

int gcd(int p, int q)
{
	if(p%q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int main()
{
	int count, i, j, k, l, c, d, t, st, dif, tim, n, m;
	long long res, tmp;
	scanf("%d", &count);
	cir[0] = 1;
	gg[0] = 1000;
	for(i=1; i<1000; i++)
	{
		cir[i] = 1000/(gg[i]=gcd(1000, i));
		for(j=0; j<gg[i]; j++)
		{
			for(k=0, l=j; k<cir[i]; k++)
			{
				tbl[i][l] = k;
				l += i;
				if(l >= 1000)
				{
					l -= 1000;
				}
			}
		}
	}
	while(count--)
	{
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		memset(pos, 0, sizeof(pos));
		memset(neg, 0, sizeof(neg));
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &st, &dif, &tim);
			st %= 1000;
			dif %= 1000;
			c = st%gg[dif];
			d = tbl[dif][st];
			pos[dif][c*cir[dif]] += tim/cir[dif];
			neg[dif][(c+1)*cir[dif]-1] += tim/cir[dif];
			t = tim%cir[dif];
			if(t)
			{
				if(d+t-1 >= cir[dif])
				{
					pos[dif][c*cir[dif]+d]++;
					neg[dif][(c+1)*cir[dif]-1]++;
					pos[dif][c*cir[dif]]++;
					neg[dif][c*cir[dif]+d+t-1-cir[dif]]++;
				}
				else
				{
					pos[dif][c*cir[dif]+d]++;
					neg[dif][c*cir[dif]+d+t-1]++;
				}
			}
		}
		for(i=0; i<1000; i++)
		{
			for(j=0, tmp=0; j<1000; j++)
			{
				tmp += pos[i][j];
				tree[i][j] = tmp;
				tmp -= neg[i][j];
			}
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &t);
			for(j=0, res=0; j<1000; j++)
			{
				c = t%gg[j];
				d = tbl[j][t];
				res += tree[j][c*cir[j]+d];
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
