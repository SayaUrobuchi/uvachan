/*
	ID: sa072682
	LANG: C
	TASK: shopping
*/
#include <stdio.h>

int dp[50000], ary[100][1000], num[100], price[5], need[5], neednum[5], cost[100], n, m;
char chk[50000];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int encode(int* ptr)
{
	int i, j, ans;
	for(i=0, j=1, ans=0; i<m; i++, j*=6)
	{
		if(ptr[i] < 0)
		{
			return -1;
		}
		ans += ptr[i] * j;
	}
	return ans;
}

void decode(int now, int* ptr)
{
	int i;
	for(i=0; i<m; i++)
	{
		ptr[i] = now % 6;
		now /= 6;
	}
}

int recursion(int now)
{
	int i, j, tbl[5];
	if(chk[now])
	{
		return dp[now];
	}
	chk[now] = 1;
	if(!now)
	{
		return 0;
	}
	dp[now] = 2147483647;
	decode(now, tbl);
	for(i=0; i<m; i++)
	{
		tbl[i]--;
		if(tbl[i] > -1)
		{
			dp[now] = min(dp[now], recursion(encode(tbl))+price[i]);
		}
		tbl[i]++;
	}
	for(i=0; i<n; i++)
	{
		if(num[i])
		{
			for(j=0; j<m; j++)
			{
				tbl[j] -= ary[i][need[j]];
			}
			if(encode(tbl) != -1 && encode(tbl) != now)
			{
				dp[now] = min(dp[now], recursion(encode(tbl))+cost[i]);
			}
			for(j=0; j<m; j++)
			{
				tbl[j] += ary[i][need[j]];
			}
		}
	}
	return dp[now];
}

int main()
{
	int i, j, o;
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &num[i]);
		for(j=0; j<num[i]; j++)
		{
			scanf("%d%d", &m, &o);
			ary[i][m] = o;
		}
		scanf("%d", &cost[i]);
	}
	scanf("%d", &m);
	if(!m)
	{
		printf("0\n");
	}
	else
	{
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &need[i], &neednum[i], &price[i]);
		}
		printf("%d\n", recursion(encode(neednum)));
	}
	scanf(" ");
	return 0;
}
