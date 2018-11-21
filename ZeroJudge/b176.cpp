#include <stdio.h>

int map[105][105], tbl[105][105];

int main()
{
	int n, m, i, j, k, l, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
				tbl[i][j] = 0;
				if(j == 0 || map[i][j] > map[i][j-1])
				{
					tbl[i][j] = 1;
					if(i == 0 || map[i][j] > map[i-1][j])
					{
						tbl[i][j] = tbl[i-1][j] + 1;
					}
				}
			}
		}
		for(i=0, ans=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				for(k=i; k>=0; k--)
				{
					if(k != 0 && map[k-1][j] >= map[k][j])
					{
						break;
					}
				}
				if(k != -1)
				{
					k--;
				}
				l = i - k;
				if(l > ans)
				{
					ans = l;
				}
				for(k=j+1; k<m&&l; k++)
				{
					if(tbl[i][k] < l)
					{
						l = tbl[i][k];
					}
					if(l * (k-j+1) > ans)
					{
						ans = l * (k-j+1);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
