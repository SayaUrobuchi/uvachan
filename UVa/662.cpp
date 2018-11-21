#include <stdio.h>
#include <string.h>

int ary[202], dp[202][32], last[202][32], stack[32];
char chk[202][32];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, n, k, i, j, p, q, temp, ans;
	cas = 0;
	while(scanf("%d%d", &n, &k) == 2)
	{
		if(!n && !k)
		{
			break;
		}
		memset(chk, 0, sizeof(chk));
		for(i=1, n++; i<n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i][0] = 0;
			for(j=1; j<i; j++)
			{
				dp[i][0] += ary[i] - ary[j];
			}
			last[i][0] = 0;
			chk[i][0] = 1;
			for(j=1; j<k; j++)
			{
				if(chk[i-1][j-1])
				{
					dp[i][j] = dp[i-1][j-1];
					last[i][j] = i - 1;
					chk[i][j] = 1;
				}
				else
				{
					break;
				}
			}
			for(j=i-2; j>0; j--)
			{
				temp = 0;
				for(q=j+1; q<i; q++)
				{
					temp += min(ary[i]-ary[q], ary[q]-ary[j]);
				}
				for(p=1; p<k; p++)
				{
					if(chk[j][p-1] && dp[j][p-1] + temp < dp[i][p])
					{
						dp[i][p] = dp[j][p-1] + temp;
						last[i][p] = j;
						chk[i][p] = 1;
					}
				}
			}
		}
		printf("Chain %d\n", ++cas);
		for(i=n-2, ans=j=dp[n-1][k-1], p=n-1; i; i--)
		{
			if(chk[i][k-1])
			{
				for(q=i+1; q<n; q++)
				{
					dp[i][k-1] += ary[q] - ary[i];
				}
				if(dp[i][k-1] < j)
				{
					ans = j = dp[i][k-1];
					p = i;
				}
			}
		}
		stack[0] = p;
		for(i=last[p][k-1], j=1, p=k-1; i; i=last[i][--p], j++)
		{
			stack[j] = i;
		}
		for(i=j-1, p=1, temp=1; i; i--, temp++)
		{
			q = stack[i];
			for(j=q+1; j<n; j++)
			{
				if(ary[j] - ary[q] > ary[stack[i-1]] - ary[j])
				{
					break;
				}
			}
			if(p == j-1)
			{
				printf("Depot %d at restaurant %d serves restaurant %d\n", temp, q, p);
			}
			else
			{
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n", temp, q, p, j-1);
			}
			p = j;
		}
		if(p == n-1)
		{
            printf("Depot %d at restaurant %d serves restaurant %d\n", temp, stack[0], p);
		}
		else
		{
			printf("Depot %d at restaurant %d serves restaurants %d to %d\n", temp, stack[0], p, n-1);
		}
		printf("Total distance sum = %d\n\n", ans);
	}
	return 0;
}
