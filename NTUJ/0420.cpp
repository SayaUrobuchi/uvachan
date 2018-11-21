#include <stdio.h>
#include <string.h>

int conn[1005][1005], map[1005][1005], mapp[1005][1005], mapp2[1005][1005], num[1005];

int main()
{
	int n, m, i, j, k, l, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(conn, 1, sizeof(conn));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			conn[i][j] = conn[j][i] = 0;
		}
		for(i=1; i<=n; i++)
		{
			conn[i][i] = 0;
			for(j=1, num[i]=0; j<=n; j++)
			{
				if(conn[i][j])
				{
					map[i][num[i]++] = j;
					printf("edge: %d => %d\n", i, j);
					mapp[i][j] = mapp2[i][j] = 1;
				}
				else
				{
					mapp[i][j] = mapp2[i][j] = 0;
				}
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=k; i++)
			{
				if(mapp[i][k] && i != k)
				{
					for(j=1; j<=k; j++)
					{
						if(mapp[k][j] && k != j && mapp[i][k] + 1 > mapp2[i][j])
						{
							mapp2[i][j] = mapp[i][k] + 1;
						}
						printf("%d => %d: %d\n", i, j, mapp2[i][j]);
					}
				}
			}
			k++;
			if(k <= n)
			{
				for(i=1; i<=k; i++)
				{
					if(mapp2[i][k] && i != k)
					{
						for(j=1; j<=k; j++)
						{
							if(mapp[k][j] && k != j && mapp2[i][k] + 1 > mapp[i][j])
							{
								mapp[i][j] = mapp2[i][k] + 1;
							}
							printf("%d => %d: %d\n", i, j, mapp[i][j]);
						}
					}
				}
			}
		}
		for(i=1, ans=0; i<=n; i++)
		{
			/*for(j=1; j<=n; j++)
			{
				if(mapp[i][j] > ans && conn[j][i])
				{
					ans = mapp[i][j];
					printf("XDD %d %d ", i, j);
					printf("%d\n", ans);
				}
				if(mapp2[i][j] > ans && conn[j][i])
				{
					ans = mapp2[i][j];
					printf("XDD %d %d ", i, j);
					printf("%d\n", ans);
				}
			}*/
			if(mapp[i][i] > ans)
			{
				ans = mapp[i][i];
				printf("%d: %d\n", i, ans);
			}
			if(mapp2[i][i] > ans)
			{
				ans = mapp2[i][i];
				printf("%d: %d\n", i, ans);
			}
		}
		printf("%d\n", n-ans);
		/*for(k=1; k<=n; k++)
		{
			queue[0] = k;
			step[0] = 0;
			memset(used, 0, sizeof(used));
		}*/
	}
	return 0;
}
