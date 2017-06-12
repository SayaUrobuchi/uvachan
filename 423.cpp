#include <stdio.h>

int map[105][105];
char str[10001];

int main()
{
	int n, i, j, k, ans;
	while(scanf("%d", &n) == 1)
	{
		map[1][1] = 0;
		for(i=2; i<=n; i++)
		{
			for(j=1; j<i; j++)
			{
				scanf("%s", str);
				if(str[0] == 'x')
				{
					map[i][j] = map[j][i] = 0;
				}
				else
				{
					sscanf(str, "%d", &map[i][j]);
					map[j][i] = map[i][j];
				}
			}
			map[i][i] = 0;
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				if(map[i][k])
				{
					for(j=1; j<=n; j++)
					{
						if(map[k][j])
						{
							if(!map[i][j] || map[i][k] + map[k][j] < map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
							}
						}
					}
				}
			}
		}
		for(i=2, ans=0; i<=n; i++)
		{
			if(map[1][i] > ans)
			{
				ans = map[1][i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
