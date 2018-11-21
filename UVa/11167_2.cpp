#include <stdio.h>
#include <string.h>

int n, m;
int maxcap[50001];
int num[50001];
int ary[50001][5];
int tbl[101][50001];
int need[101], lbound[101], rbound[101];
int used[50201];
int queue[50201];
int from[50201];
int record[50201];
int ansx[50001], ansy[50001];

void backtracking(int now)
{
	int u, v;
	if(from[now] == -1)
	{
		need[queue[now]]--;
	}
	else
	{
		backtracking(from[now]);
		u = queue[from[now]];
		v = queue[now];
		if(u < n)
		{
			v -= n;
			tbl[u][v] = 1;
			/*printf("%d %d: enable\n", u, v);*/
			ary[v][num[v]++] = u;
		}
		else
		{
			u -= n;
			ary[u][record[now]] = ary[u][--num[u]];
			/*printf("%d %d: disable\n", v, u);*/
			tbl[v][u] = 0;
		}
	}
}

int main()
{
	int cas, i, j, k, l, temp, now, flag;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		memset(tbl, 0, sizeof(tbl));
		memset(maxcap, 0, sizeof(maxcap));
		scanf("%d", &m);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &need[i], &lbound[i], &rbound[i]);
			for(j=lbound[i]; j<rbound[i]; j++)
			{
				maxcap[j]++;
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=lbound[i]; j<rbound[i]&&need[i]; j++)
			{
				if(maxcap[j] <= m)
				{
					need[i]--;
					tbl[i][j] = 1;
					ary[j][num[j]++] = i;
				}
			}
		}
		for(; ; )
		{
			memset(used, 0, sizeof(used));
			for(i=0, j=0; i<n; i++)
			{
				if(need[i])
				{
					queue[j] = i;
					from[j++] = -1;
					used[i] = 1;
				}
			}
			for(i=0, flag=0; i<j; i++)
			{
				now = queue[i];
				if(now < n)
				{
					for(k=lbound[now]; k<rbound[now]; k++)
					{
						if(!tbl[now][k] && !used[n+k])
						{
							queue[j] = n + k;
							from[j++] = i;
							used[n+k] = 1;
						}
					}
				}
				else
				{
					now -= n;
					if(num[now] < m)
					{
						flag = 1;
						temp = i;
						break;
					}
					else
					{
						for(k=0; k<m; k++)
						{
							if(!used[ary[now][k]])
							{
								queue[j] = ary[now][k];
								from[j] = i;
								used[ary[now][k]] = 1;
								record[j++] = k;
							}
						}
					}
				}
			}
			if(!j || !flag)
			{
				break;
			}
			backtracking(temp);
			/*printf("\n");*/
		}
		if(j)
		{
			printf("Case %d: No\n", ++cas);
		}
		else
		{
			printf("Case %d: Yes\n", ++cas);
			for(i=0; i<n; i++)
			{
				/*for(j=lbound[i]; j<rbound[i]; j++)
				{
					printf("tbl %d %d = %d;\n", i, j, tbl[i][j]);
				}*/
				for(j=lbound[i], l=0; j<rbound[i]; j=temp)
				{
					for(k=j; !tbl[i][k]; k++);
					for(temp=k+1; tbl[i][temp]; temp++);
					ansx[l] = k;
					ansy[l++] = temp;
				}
				printf("%d", l);
				for(j=0; j<l; j++)
				{
					printf(" (%d,%d)", ansx[j], ansy[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
