#include <stdio.h>

long long ary[20][20][20];

long long max(long long p, long long q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int count, i, j, k, n, m, o, p, q;
	long long maximum, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				for(k=0; k<o; k++)
				{
					scanf("%lld", &ary[i][j][k]);
					if(i)
					{
						ary[i][j][k] += ary[i-1][j][k];
					}
					if(j)
					{
						ary[i][j][k] += ary[i][j-1][k];
					}
					if(i && j)
					{
						ary[i][j][k] -= ary[i-1][j-1][k];
					}
				}
			}
		}
		for(i=0, ans=-214748364700000ll; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				for(p=0; p<m; p++)
				{
					for(q=0; q<=p; q++)
					{
						for(k=0, maximum=0; k<o; k++)
						{
							maximum += ary[i][p][k];
							if(j)
							{
								maximum -= ary[j-1][p][k];
							}
							if(q)
							{
								maximum -= ary[i][q-1][k];
							}
							if(j && q)
							{
								maximum += ary[j-1][q-1][k];
							}
							ans = max(ans, maximum);
							maximum = max(maximum, 0);
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
