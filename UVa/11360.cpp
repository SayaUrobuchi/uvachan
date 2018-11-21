#include <stdio.h>
#include <string.h>

char map[15][15];
char tbl[15][15];
char buf[2008];

int main()
{
	int cas, count, n, m, i, j, now, target, temp;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s", buf);
			if(!strcmp(buf, "row"))
			{
				scanf("%d%d", &now, &target);
				now--;
				target--;
				for(i=0; i<n; i++)
				{
					temp = map[now][i];
					map[now][i] = map[target][i];
					map[target][i] = temp;
				}
			}
			else if(!strcmp(buf, "col"))
			{
				scanf("%d%d", &now, &target);
				now--;
				target--;
				for(i=0; i<n; i++)
				{
					temp = map[i][now];
					map[i][now] = map[i][target];
					map[i][target] = temp;
				}
			}
			else if(!strcmp(buf, "inc"))
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						map[i][j]++;
						if(map[i][j] == 58)
						{
							map[i][j] -= 10;
						}
					}
				}
			}
			else if(!strcmp(buf, "dec"))
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						map[i][j]--;
						if(map[i][j] == 47)
						{
							map[i][j] += 10;
						}
					}
				}
			}
			else
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						tbl[i][j] = map[j][i];
					}
					tbl[i][j] = 0;
				}
				memcpy(map, tbl, sizeof(tbl));
			}
		}
		printf("Case #%d\n", ++cas);
		for(i=0; i<n; i++)
		{
			puts(map[i]);
		}
		printf("\n");
	}
	return 0;
}
