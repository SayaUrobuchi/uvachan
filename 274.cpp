#include <stdio.h>
#include <string.h>

int map[101][101];
int mmap[101][101];
int cmap[101][101];
char buf[1005];

int main()
{
	int count, n, m, c, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &c, &m);
		memset(cmap, 0, sizeof(cmap));
		cmap[c][c] = 1;
		while(scanf("%d%d", &i, &j) == 2)
		{
			if(i == -1 && j == -1)
			{
				break;
			}
			cmap[i][j] = 1;
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				if(cmap[i][k])
				{
					for(j=1; j<=n; j++)
					{
						cmap[i][j] |= (cmap[i][k] && cmap[k][j]);
					}
				}
			}
		}
		memset(map, 0, sizeof(map));
		memset(mmap, 0, sizeof(mmap));
		mmap[m][m] = 1;
		gets(buf);
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			sscanf(buf, "%d%d", &i, &j);
			mmap[i][j] = 1;
			map[i][j] = 1;
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				if(mmap[i][k])
				{
					for(j=1; j<=n; j++)
					{
						mmap[i][j] |= (mmap[i][k] && mmap[k][j]);
						map[i][j] |= (map[i][k] && map[k][j] && !cmap[c][i] && !cmap[c][j] && !cmap[c][k]);
					}
				}
			}
		}
		for(i=1; i<=n; i++)
		{
			if(cmap[c][i] && mmap[m][i])
			{
				break;
			}
		}
		if(i > n)
		{
			printf("N ");
		}
		else
		{
			printf("Y ");
		}
		if(map[m][m])
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
