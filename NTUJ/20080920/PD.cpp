#include <stdio.h>
#include <string.h>

int num[25], map[25][25], used[25], ud[25], col[25], cn;
double px[25], py[25];

double getdis(double p, double q)
{
	return p*p + q*q;
}

int dfs(int nod)
{
	int i, j, ans, tbl[13];
	used[nod] = 1;
	ud[nod] = 1;
	memset(tbl, 0, sizeof(tbl));
	for(i=0; i<num[nod]; i++)
	{
		if(used[map[nod][i]])
		{
			tbl[col[map[nod][i]]] = 1;
		}
	}
	for(i=0, ans=0; i<cn; i++)
	{
		if(tbl[i] == 0)
		{
			col[nod] = i;
			for(j=0; j<num[nod]; j++)
			{
				if(used[map[nod][j]] == 0)
				{
					if(dfs(map[nod][j]) == 0)
					{
						break;
					}
				}
			}
			if(j == num[nod])
			{
				used[nod] = 0;
				return 1;
			}
		}
	}
	used[nod] = 0;
	return 0;
}

int main()
{
	int cas, n, i, j;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &px[i], &py[i]);
			for(j=0; j<i; j++)
			{
				if(getdis(px[i]-px[j], py[i]-py[j]) <= 400+1e-4)
				{
					map[i][num[i]++] = j;
					map[j][num[j]++] = i;
				}
			}
		}
		for(cn=1; ; cn++)
		{
			memset(used, 0, sizeof(used));
			memset(ud, 0, sizeof(ud));
			for(j=0; j<n; j++)
			{
				if(ud[j] == 0)
				{
					if(dfs(j) == 0)
					{
						break;
					}
				}
			}
			if(j == n)
			{
				break;
			}
		}
		printf("The towers in case %d can be covered in %d frequencies.\n", ++cas, cn);
	}
	return 0;
}
