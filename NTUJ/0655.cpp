#include <stdio.h>
#include <string.h>

int dp[55][2][3][7], used[55][2][3][7];
int tp1[100001], tp2[100001], tp3[100001];
char buf[100001];

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int n, m, i, j, p, q, r, f, temp, cnt;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(used, 0, sizeof(used));
		dp[0][0][0][0] = 0;
		used[0][0][0][0] = 1;
		for(i=1; i<=n; i++)
		{
			scanf("%d:", &temp);
			cnt = 0;
			while(scanf("%s", buf) == 1)
			{
				sscanf(buf, "(%d,%d,%d", &tp1[cnt], &tp2[cnt], &tp3[cnt]);
				cnt++;
				if(buf[strlen(buf)-1] == ';')
				{
					break;
				}
				scanf("%s", buf);
			}
			for(p=1; p>=0; p--)
			{
				for(q=2; q>=0; q--)
				{
					for(r=6; r>=0; r--)
					{
						if(used[i-1][p][q][r])
						{
							used[i][p][q][r] = 1;
							dp[i][p][q][r] = dp[i-1][p][q][r];
						}
						for(j=0, f=0; j<cnt; j++)
						{
							if(p >= tp1[j] && q >= tp2[j] && r >= tp3[j])
							{
								if(used[i-1][p-tp1[j]][q-tp2[j]][r-tp3[j]])
								{
									if(used[i][p][q][r] == 0)
									{
										used[i][p][q][r] = 1;
										dp[i][p][q][r] = 0;
									}
									dp[i][p][q][r] = max(dp[i][p][q][r], dp[i-1][p-tp1[j]][q-tp2[j]][r-tp3[j]]+temp);
								}
							}
						}
					}
				}
			}
		}
		for(p=0; p<=1; p++)
		{
			for(q=0; q<=2; q++)
			{
				for(r=0; r<=6; r++)
				{
					if(used[n][p][q][r] && dp[n][p][q][r] >= m)
					{
						break;
					}
				}
				if(r <= 6)
				{
					break;
				}
			}
			if(q <= 2)
			{
				break;
			}
		}
		if(p <= 1)
		{
			printf("%d %d %d\n", 1-p, 2-q, 6-r);
		}
		else
		{
			/*printf("1 2 6\n");*/
			printf("0 0 0\n");
		}
	}
	return 0;
}
