#include <iostream>

int ucnt, used[1048576];
int prime[1048576], tbl[1048576], pn;
int ary[1048576], cnt[1048576];

int main()
{
	int n, i, j, k, t, u, lim, ans;
	long long res;
	prime[0] = 2;
	pn = 1;
	for (i=3; i<1000000; i+=2)
	{
		if (!tbl[i])
		{
			tbl[i] = -pn;
			prime[pn++] = i;
			if ((long long)i*i < 1000000)
			{
				for (j=i*i, k=i+i; j<=1000000; j+=k)
				{
					tbl[j] = i;
				}
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		++ucnt;
		for (i=0, lim=-1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			for (t=ary[i]; t>1; t/=u)
			{
				if (!(t & 1))
				{
					u = 2;
					k = 0;
				}
				else if (tbl[t] <= 0)
				{
					u = t;
					k = -tbl[t];
				}
				else
				{
					u = tbl[t];
					k = -tbl[u];
				}
				if (used[k] != ucnt)
				{
					cnt[k] = 0;
					used[k] = ucnt;
					lim = std::max(lim, k);
				}
				++cnt[k];
			}
		}
		for (i=0, res=1, ans=0; i<=lim; i++)
		{
			if (used[i] == ucnt && cnt[i] >= n)
			{
				t = cnt[i] / n;
				for (j=0; j<t; j++)
				{
					res *= prime[i];
				}
				for (j=0; j<n; j++)
				{
					for (k=0, u=ary[j]; k<t&&u%prime[i]==0; k++, u/=prime[i]);
					if (k < t)
					{
						ans += t - k;
					}
				}
			}
		}
		printf("%lld %d\n", res, ans);
	}
	return 0;
}
