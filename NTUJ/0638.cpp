#include <stdio.h>
#include <string.h>

int res;
int dp[201][201][201], used[201][201][201], col[201], cnt[201];
int list[201][201], lnum[201];

int calc(int t)
{
	return t*t;
}

int bisearch(int tar, int p, int q, int *arr)
{
	int c;
	if(p > q)
	{
		return res;
	}
	c = ((p+q) >> 1);
	if(arr[c] >= tar)
	{
		return bisearch(tar, p, c-1, arr);
	}
	res = c;
	return bisearch(tar, c+1, q, arr);
}

int recurs(int p, int q, int r)
{
	int t, tt;
	if(q < p)
	{
		return 0;
	}
	if(used[p][q][r])
	{
		return dp[p][q][r];
	}
	used[p][q][r] = 1;
	dp[p][q][r] = recurs(p, q-1, 0) + calc(r+cnt[q]);
	res = -1;
	if((t = bisearch(q, 0, lnum[col[q]]-1, list[col[q]])) != -1)
	{
		for(; t>=0&&list[col[q]][t]>=p; t--)
		{
			tt = recurs(p, list[col[q]][t], r+cnt[q]) + recurs(list[col[q]][t]+1, q-1, 0);
			if(tt > dp[p][q][r])
			{
				dp[p][q][r] = tt;
			}
		}
	}
	return dp[p][q][r];
}

int main()
{
	int n, m, i, t, last;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(cnt, 0, sizeof(cnt));
		memset(lnum, 0, sizeof(lnum));
		for(i=0, last=-1, m=-1; i<n; i++)
		{
			scanf("%d", &t);
			if(t != last)
			{
				m++;
				col[m] = t;
				cnt[m] = 1;
				list[t][lnum[t]++] = m;
				last = t;
			}
			else
			{
				cnt[m]++;
			}
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recurs(0, m, 0));
	}
	return 0;
}
