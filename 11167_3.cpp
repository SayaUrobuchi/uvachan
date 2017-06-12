#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 320

int map[N][N];
int list[N];
int cap[N];
int used[N];
int id[N];
int ll[N], rl[N];
int queue[N];
int qflow[N];
int from[N];
int aryl[N], aryr[N];
int tbl[50005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, n, m, i, j, k, l, f, t, u, v, now, temp, left, right;
	/*freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);*/
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d", &m);
		memset(map, 0, sizeof(map));
		for(i=1, j=0; i<=n; i++)
		{
			scanf("%d%d%d", &map[0][i], &ll[i], &rl[i]);
			list[j++] = ll[i];
			list[j++] = rl[i];
		}
		qsort(list, j, sizeof(int), comp);
		for(i=1, k=1; i<j; i++)
		{
			if(list[i-1] != list[i])
			{
				ll[n+k] = left = list[i-1];
				rl[n+k] = right = list[i] - 1;
				cap[n+k] = right - left + 1;
				/*printf("%d: %d %d\n", n+k, left, right);*/
				for(l=1; l<=n; l++)
				{
					/*if(ll[l] <= right && rl[l] > left)*/
					if(ll[l] <= left && rl[l] > right)
					{
						map[l][n+k] = cap[n+k];
					}
				}
				k++;
			}
		}
		t = n + k;
		for(i=n+1; i<t; i++)
		{
			map[i][t] = cap[i] * m;
		}
		for(; ; )
		{
			memset(used, 0, sizeof(used));
			queue[0] = 0;
			qflow[0] = 1 << 30;
			from[0] = -1;
			used[0] = 1;
			for(i=0, j=1; i<j; i++)
			{
				now = queue[i];
				f = qflow[i];
				if(!now || now > n)
				{
					if(temp=map[now][t])
					{
						queue[j] = t;
						qflow[j] = min(temp, f);
						from[j] = i;
						break;
					}
					for(k=1; k<=n; k++)
					{
						if(!used[k] && (temp=map[now][k]))
						{
							used[k] = 1;
							queue[j] = k;
							qflow[j] = min(temp, f);
							from[j++] = i;
						}
					}
				}
				else
				{
					for(k=n+1; k<t; k++)
					{
						if(!used[k] && (temp=map[now][k]))
						{
							used[k] = 1;
							queue[j] = k;
							qflow[j] = min(temp, f);
							from[j++] = i;
						}
					}
				}
			}
			if(i < j)
			{
				f = qflow[j];
				/*printf("%d\n", f);*/
				for(; from[j]!=-1; j=from[j])
				{
					u = queue[from[j]];
					v = queue[j];
					/*printf("%d => %d\n", u, v);
					printf("%d from %d\n", j, from[j]);*/
					map[u][v] -= f;
					map[v][u] += f;
				}
			}
			else
			{
				break;
			}
		}
		for(i=1; i<=n; i++)
		{
			if(map[0][i])
			{
				/*printf("%d: %d\n", i, map[0][i]);*/
				break;
			}
		}
		if(i > n)
		{
			printf("Case %d: Yes\n", ++cas);
			for(i=1; i<=n; i++)
			{
				memset(tbl, 0, sizeof(tbl));
				for(j=n+1; j<t; j++)
				{
					if(temp=map[j][i])
					{
						for(k=ll[j], l=0; l<temp; k++, l++)
						{
							if(k > rl[j])
							{
								k -= cap[j];
							}
							tbl[k] = 1;
						}
						ll[j] = k;
					}
				}
				for(j=ll[i], k=0; j<=rl[i]; j++)
				{
					if(tbl[j])
					{
						aryl[k] = j;
						for(j++; tbl[j]&&j<=rl[i]; j++);
						aryr[k++] = j;
					}
				}
				if(k >= N)
				{
					while(1);
				}
				printf("%d", k);
				for(j=0; j<k; j++)
				{
					printf(" (%d,%d)", aryl[j], aryr[j]);
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
