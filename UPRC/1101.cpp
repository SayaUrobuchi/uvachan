#include <stdio.h>
#include <string.h>

int id[110], dp[105][105], cost[110], ary[110], tbl[128];
char *str[110], sbuf[110][105];

int get_cost(char *p, char *q)
{
	int i, j, pl, ql;
	pl = strlen(p);
	ql = strlen(q);
	p--;
	q--;
	for(i=1; i<=pl; i++)
	{
		for(j=1; j<=ql; j++)
		{
			if(tbl[p[i]] == tbl[q[j]])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = dp[i-1][j] + 1;
				if(dp[i][j] > dp[i][j-1] + 1)
				{
					dp[i][j] = dp[i][j-1] + 1;
				}
				if(dp[i][j] > dp[i-1][j-1] + 1)
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
			}
		}
	}
	return dp[pl][ql];
}

int main()
{
	int n, i, j, k, t;
	char s[110];
	for(i=0; i<128; i++)
	{
		tbl[i] = i;
	}
	for(i=0; i<26; i++)
	{
		tbl['a'+i] = tbl['A'+i];
	}
	for(i=0; i<105; i++)
	{
		dp[i][0] = dp[0][i] = i;
	}
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &id[i]);
			gets(sbuf[i]);
			str[i] = sbuf[i];
			while(*str[i]==' ')
			{
				str[i]++;
			}
		}
		gets(s);
		for(i=0, j=0; i<n; i++)
		{
			cost[i] = get_cost(s, str[i]);
			if(cost[i] == 0)
			{
				break;
			}
			ary[j++] = i;
			for(k=j-1; k; k--)
			{
				if(cost[ary[k]] < cost[ary[k-1]])
				{
					t = ary[k];
					ary[k] = ary[k-1];
					ary[k-1] = t;
				}
				else if(cost[ary[k]] == cost[ary[k-1]] && id[ary[k]] < id[ary[k-1]])
				{
					t = ary[k];
					ary[k] = ary[k-1];
					ary[k-1] = t;
				}
				else
				{
					 break;
				}
			}
			if(j > 5)
			{
				j = 5;
			}
		}
		if(i < n)
		{
			printf("yes:%d\n", id[i]);
		}
		else
		{
			for(i=0; i<j; i++)
			{
				printf("%d %s\n", id[ary[i]], str[ary[i]]);
			}
		}
	}
	return 0;
}
