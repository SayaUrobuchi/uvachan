#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long ans;
int ary[4203], son[40000][20], prime[4203], snum[40000];

int dfs(int now)
{
	int i, tmp;
	if(snum[now] != -1) return snum[now];
	snum[now] = son[now][0] - 1;
	for(i=1, tmp=son[now][0]; i<tmp; i++)
	{
		snum[now] += dfs(son[now][i]);
	}
	return snum[now];
}

int main()
{
	int sq, n, m, i, j, k, count, in, in2, tmp;
	prime[0] = 2;
	prime[1] = 3;
	for(i=5, k=2; i<40001; i++)
	{
		for(j=0; j<k; j++)
		{
			if(!(i % prime[j])) break;
		}
		if(j == k) prime[k++] = i;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<k; i++)
		{
			if(prime[i] > n) break;
			tmp = n;
			ary[i] = 0;
			j = prime[i];
			while(tmp)
			{
				tmp /= j;
				ary[i] += tmp;
			}
		}
		sq = i;
		for(i=0; i<n; i++)
		{
			son[i][0] = 1;
			snum[i] = -1;
		}
		while(m--)
		{
			scanf("%d%d", &in, &in2);
			son[in2-1][son[in2-1][0]++] = in - 1;
		}
		for(i=0; i<n; i++)
		{
			if(snum[i] == -1) snum[i] = dfs(i);
			if(!snum[i]) continue;
			tmp = snum[i] + 1;
			for(j=0; j<sq; j++)
			{
				m = prime[j];
				if(!(tmp % m))
				{
					while(!(tmp % m))
					{
						ary[j]--;
						tmp /= m;
					}
					if(tmp == 1) break;
				}
			}
		}
		ans = 1;
		for(i=0; i<sq; i++)
		{
			tmp = prime[i];
			m = ary[i];
			for(j=0; j<m; j++)
			{
				ans *= tmp;
				if(ans > 1000000007) ans %= 1000000007;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
