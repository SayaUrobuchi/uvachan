#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pnum[5]={1, 1, 2, 3, 5};
int part[5][5]={{0}, {1}, {2, 1}, {3, 2, 1}, {4, 3, 2, 2, 1}};
int cost[5][5]={{0}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 2, 3}};
int perm[5][5]={{1}, {1}, {2, 2}, {6, 12, 6}, {24, 72, 48, 24, 24}};
int tbl[20], hash[128], list[55], used[55];
long long c[55][55], fac[10], m;
char ary[55][5];
double dp[15][55];

int comp(const void *p, const void *q)
{
	if(*(char*)p != *(char*)q)
	{
		return *(char*)p - *(char*)q;
	}
	return *((char*)p+1) - *((char*)q+1);
}

long long calc(int head)
{
	int i, j, k, l, p, q, r, sum;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(i=1, sum=0; i<=14; i++)
	{
		if(i == head)
		{
			tbl[14] = tbl[i];
			tbl[i] = 0;
		}
		else if(i == 14)
		{
			sum--;
		}
		if(tbl[i] == 0)
		{
			memcpy(dp[i], dp[i-1], sizeof(dp[0]));
			continue;
		}
		for(j=0; j<pnum[tbl[i]]; j++)
		{
			p = part[tbl[i]][j];
			q = cost[tbl[i]][j];
			r = perm[tbl[i]][j];
			for(k=0; k<=sum+1; k++)
			{
				if(dp[i-1][k])
				{
					for(l=0; l<=p&&l<=k; l++)
					{
						dp[i][k-l+q] += dp[i-1][k] * c[k][l] * c[sum-k+1][p-l] * r;
					}
				}
			}
		}
		sum += tbl[i];
	}
	tbl[head] = tbl[14];
	return dp[14][0]>m?m+1:(long long)dp[14][0];
}

int main()
{
	int cas, n, i, j, last;
	long long cnt;
	cas = 0;
	c[0][0] = 1;
	for(i=1; i<55; i++)
	{
		c[i][0] = 1;
		for(j=1; j<55; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	fac[0] = 1;
	for(i=1; i<10; i++)
	{
		fac[i] = fac[i-1] * i;
	}
	for(i='2'; i<='9'; i++)
	{
		hash[i] = i-'1';
	}
	hash['T'] = 9;
	hash['J'] = 10;
	hash['Q'] = 11;
	hash['K'] = 12;
	hash['A'] = 13;
	while(scanf("%d%lld", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
			used[i] = 0;
			tbl[hash[ary[i][0]]]++;
		}
		qsort(ary, n, sizeof(ary[0]), comp);
		for(i=0; i<n; i++)
		{
			for(j=0, last=0; j<n; j++)
			{
				if(used[j] == 0 && (i==0 || *ary[j] != *ary[list[i-1]]))
				{
					tbl[hash[ary[j][0]]]--;
					cnt = calc(hash[ary[j][0]]);
					if(cnt >= m)
					{
						list[i] = j;
						used[j] = 1;
						break;
					}
					m -= cnt;
					tbl[hash[ary[j][0]]]++;
					last = cnt;
				}
			}
			if(i == 0 && j >= n)
			{
				break;
			}
		}
		if(i < n)
		{
			printf("Case %d: Not found\n", ++cas);
		}
		else
		{
			printf("Case %d:", ++cas);
			for(i=0; i<n; i++)
			{
				printf(" %s", ary[list[i]]);
			}
			printf("\n");
		}
	}
	return 0;
}
