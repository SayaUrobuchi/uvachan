#include <stdio.h>

int ary[15];
char chk[15];
double map[51][51], tbl[15], ans;

void dfs(int now, double value, int k)
{
	int i;
	/*printf("%.2f\n", value+map[now][0]);*/
	if(value + map[now][0] < ans)
	{
		ans = value + map[now][0];
	}
	for(i=0; i<k; i++)
	{
		if(chk[i])
		{
			chk[i] = 0;
			dfs(ary[i], value+map[now][ary[i]]-tbl[ary[i]], k);
			chk[i] = 1;
		}
	}
}

int main()
{
	int count, n, m, i, j, k;
	double temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			{
				map[i][j] = -1;
			}
			tbl[i] = 0;
		}
		while(m--)
		{
			scanf("%d%d%lf", &i, &j, &temp);
			map[i][j] = map[j][i] = temp;
		}
		for(k=0; k<=n; k++)
		{
			for(i=0; i<=n; i++)
			{
				if(!(map[i][k] < 0))
				{
					/*printf("XDD %.2f\n", map[i][k]);*/
					for(j=0; j<=n; j++)
					{
						if(!(map[k][j] < 0) && (map[i][j] < 0 || map[i][k] + map[k][j] < map[i][j]))
						{
							map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}
		}
		scanf("%d", &m);
		for(i=0, k=0; i<m; i++)
		{
			scanf("%d%lf", &j, &temp);
			if(!(tbl[j] > 0))
			{
				chk[k] = 1;
				ary[k++] = j;
			}
			tbl[j] += temp;
		}
		ans = 0;
		dfs(0, 0, k);
		if(ans < 0)
		{
			printf("Daniel can save $%.2f\n", -ans);
		}
		else
		{
			printf("Don't leave the house\n");
		}
	}
	return 0;
}
