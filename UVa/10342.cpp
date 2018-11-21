#include <stdio.h>
#include <string.h>

int map[100][100], map2[100][100], ext[100], ex[100][100];

int main()
{
	int cas, n, m, i, j, k, exmin;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(map, 0, sizeof(map));
		memset(map2, 0, sizeof(map2));
		memset(ext, 0, sizeof(ext));
		memset(ex, 0, sizeof(ex));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = k;
			map[j][i] = k;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(map[i][j])
				{
					if(ext[i] > map[i][j] || !ext[i])
					{
						ext[i] = map[i][j];
					}
				}
			}
			ext[i] += ext[i];
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(map[i][j])
				{
					ex[i][j] = ext[i];
					if(ex[i][j] > ext[j])
					{
						ex[i][j] = ext[j];
					}
				}
			}
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							exmin = ex[i][k];
							if(exmin > ex[k][j])
							{
								exmin = ex[k][j];
							}
							if(!map[i][j])
							{
								map[i][j] = map[i][k] + map[k][j];
								if(map2[i][k])
								{
									map2[i][j] = map2[i][k] + map[k][j];
								}
								if(map2[k][j] && (!map2[i][j] || map[i][k] + map2[k][j] < map2[i][j]))
								{
									map2[i][j] = map[i][k] + map2[k][j];
								}
								ex[i][j] = exmin;
							}
							else
							{
								if(map[i][k] + map[k][j] < map[i][j])
								{
									map2[i][j] = map[i][j];
									map[i][j] = map[i][k] + map[k][j];
									ex[i][j] = exmin;
									if(map2[i][k] && map2[i][k] + map[k][j] < map2[i][j])
									{
										map2[i][j] = map2[i][k] + map[k][j];
									}
									if(map2[k][j] && map[i][k] + map2[k][j] < map2[i][j])
									{
										map2[i][j] = map[i][k] + map2[k][j];
									}
								}
								else if(map[i][k] + map[k][j] == map[i][j])
								{
									if(exmin < ex[i][j])
									{
										ex[i][j] = exmin;
									}
									if(map2[i][k] && (!map2[i][j] || map2[i][k] + map[k][j] < map2[i][j]))
									{
										map2[i][j] = map2[i][k] + map[k][j];
									}
									if(map2[k][j] && (!map2[i][j] || map[i][k] + map2[k][j] < map2[i][j]))
									{
										map2[i][j] = map[i][k] + map2[k][j];
									}
								}
								else if(!map2[i][j] || map[i][k] + map[k][j] < map2[i][j])
								{
									map2[i][j] = map[i][k] + map[k][j];
								}
							}
						}
					}
				}
			}
		}
		printf("Set #%d\n", ++cas);
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d", &i, &j);
			if(!map[i][j])
			{
				printf("?\n");
			}
			else
			{
                if(i == j)
				{
					printf("%d\n", map[i][j]);
				}
				else
				{
					if(map2[i][j] && map2[i][j] < map[i][j] + ex[i][j])
					{
						printf("%d\n", map2[i][j]);
					}
					else
					{
						printf("%d\n", map[i][j] + ex[i][j]);
					}
				}
			}
		}
	}
	return 0;
}
