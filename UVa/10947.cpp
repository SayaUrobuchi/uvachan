#include <stdio.h>

int island[101][3], len;
char dis[101];

char con(int x1, int y1, int r1, int x2, int y2, int r2)
{
	return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) <= (r1 + r2 + len) * (r1 + r2 + len);
}

int main()
{
	int n, i, j, x, y, r, sx, sy, sr, k, m, c;
	while(scanf("%d%d", &k, &m) == 2)
	{
		len = k * m;
		scanf("%d%d%d%d%d%d%d", &sx, &sy, &sr, &island[0][0], &island[0][1], &island[0][2], &n);
		dis[0] = con(sx, sy, sr, island[0][0], island[0][1], island[0][2]);
		for(i=1, n++; i<n; i++)
		{
			scanf("%d%d%d", &island[i][0], &island[i][1], &island[i][2]);
			dis[i] = con(sx, sy, sr, island[i][0], island[i][1], island[i][2]);
		}
		if(dis[0])
		{
			printf("Larry and Ryan will escape!\n");
		}
		else
		{
			while(1)
			{
				for(i=1, c=1; i<n; i++)
				{
					if(dis[i] == 1)
					{
						c = 0;
						dis[i] = 2;
						if(con(island[i][0], island[i][1], island[i][2], island[0][0], island[0][1], island[0][2]))
						{
							printf("Larry and Ryan will escape!\n");
							break;
						}
						for(j=1; j<n; j++)
						{
							if(!dis[j])
							{
								dis[j] = con(island[i][0], island[i][1], island[i][2], island[j][0], island[j][1], island[j][2]);
							}
						}
					}
				}
				if(c)
				{
					printf("Larry and Ryan will be eaten to death.\n");
					break;
				}
				if(i < n)
				{
					break;
				}
			}
		}
	}
	return 0;
}
