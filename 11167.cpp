#include <stdio.h>
#include <string.h>

int m;
int count[101];
int dnum[50001];
int drink[50001][5];
int monkey[101];
int mptr[101];
int lbound[101], rbound[101];
int aryx[50001], aryy[50001];
char time[50001];
char tbl[101][50001];

int fill(int);

int dodrink(int now, int pre)
{
	int i;
	if(dnum[now] < m)
	{
		drink[now][dnum[now]++] = pre;
		return 1;
	}
	for(i=0; i<m; i++)
	{
		if(!monkey[drink[now][i]])
		{
			if(fill(drink[now][i]))
			{
				tbl[drink[now][i]][now] = 0;
				drink[now][i] = pre;
				return 1;
			}
		}
	}
	return 0;
}

int fill(int now)
{
	int i;
	monkey[now] = 1;
	/*for(; mptr[now]<=rbound[now]; mptr[now]++)
	{
		if(dnum[mptr[now]] < m)
		{
			drink[mptr[now]][dnum[mptr[now]]++] = now;
			tbl[now][mptr[now]] = 1;
			mptr[now]++;
			return 1;
		}
	}*/
	for(i=lbound[now]; i<=rbound[now]; i++)
	{
		if(!tbl[now][i] && !time[i])
		{
			time[i] = 1;
			if(dodrink(i, now))
			{
				tbl[now][i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, n, i, j, k, c, left, maxbound;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d", &m);
		for(i=0, maxbound=0; i<n; i++)
		{
			scanf("%d%d%d", &count[i], &lbound[i], &rbound[i]);
			if(rbound[i] > maxbound)
			{
				maxbound = rbound[i];
			}
			mptr[i] = ++lbound[i];
			memset(tbl[i], 0, rbound[i]+2);
		}
		memset(dnum, 0, sizeof(dnum));
		for(i=0; i<n; i++)
		{
			for(; count[i]; count[i]--)
			{
				memset(monkey, 0, sizeof(monkey));
				memset(time, 0, maxbound+1);
				if(!fill(i))
				{
					break;
				}
			}
			if(count[i])
			{
				break;
			}
		}
		if(i == n)
		{
			printf("Case %d: Yes\n", ++cas);
			for(i=0; i<n; i++)
			{
				for(j=lbound[i], k=0, c=0; j<=rbound[i]+1; j++)
				{
					if(tbl[i][j])
					{
						if(!c)
						{
							left = j;
						}
						c++;
					}
					else
					{
						if(c)
						{
							aryx[k] = left - 1;
							aryy[k++] = j - 1;
						}
						c = 0;
					}
				}
				printf("%d", k);
				for(j=0; j<k; j++)
				{
					printf(" (%d,%d)", aryx[j], aryy[j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Case %d: No\n", ++cas);
		}
	}
	return 0;
}
