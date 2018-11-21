#include <stdio.h>
#include <string.h>

int ary[105][2], dp[105][201];
char chk[105][201];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

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
	int count, n, m, i, j, k, l, p, q, dis;
	char buf[100];
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		n = 0;
		scanf("%d", &m);
		gets(buf);
		while(gets(buf))
		{
			if(sscanf(buf, "%d%d", &ary[n][0], &ary[n][1]) != 2)
			{
				break;
			}
			n++;
		}
		if(!n)
		{
			if(!m)
			{
				printf("0\n");
			}
			else
			{
				printf("Impossible\n");
			}
			if(count)
			{
				printf("\n");
			}
			continue;
		}
		ary[n][0] = m;
		memset(dp, 0, sizeof(dp));
		memset(chk, 0, sizeof(chk));
		if(ary[0][0] > 100)
		{
			printf("Impossible\n");
		}
		else
		{
			for(i=0; i<n; i++)
			{
				if(ary[i][0] < 101)
				{
					chk[i][100-ary[i][0]] = 1;
				}
				else
				{
					break;
				}
			}
			for(i=0; i<n; i++)
			{
				dis = ary[i+1][0] - ary[i][0];
				if(dis > 200)
				{
					break;
				}
				for(j=0; j<201; j++)
				{
					if(chk[i][j])
					{
						for(k=max(0, j-dis), l=201-dis, p=ary[i][1]*max(dis-j, 0); k<l; k++, p+=ary[i][1])
						{
							if(chk[i+1][k])
							{
								dp[i+1][k] = min(dp[i+1][k], dp[i][j] + p);
							}
							else
							{
								dp[i+1][k] = dp[i][j] + p;
								chk[i+1][k] = 1;
							}
						}
					}
				}
			}
			if(i < n)
			{
				printf("Impossible\n");
			}
			else
			{
				for(i=100, j=-1; i<201; i++)
				{
					if(chk[n][i])
					{
						if(dp[n][i] < j || j == -1)
						{
							j = dp[n][i];
						}
					}
				}
				if(j == -1)
				{
					printf("Impossible\n");
				}
				else
				{
					printf("%d\n", j);
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
