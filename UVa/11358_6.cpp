#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 150

int map[N][N];
int left[N], right[N];
int list[N];
int cap[N];
int used[N];
int queue[N], qflow[N];
int from[N];

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
	int count, n, m, i, j, k, l, f, t, u, v, now;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		memset(map, 0, sizeof(map));
		for(i=1, j=0; i<=n; i++)
		{
			scanf("%d%d%d", &left[i], &map[0][i], &right[i]);
			list[j++] = left[i];
			list[j++] = right[i];
		}
		qsort(list, j, sizeof(int), comp);
		for(i=1, k=1; i<j; i++)
		{
			if(list[i] != list[i-1])
			{
				u = left[n+k] = list[i-1];
				v = right[n+k] = list[i] - 1;
				cap[n+k] = v - u + 1;
				for(l=1; l<=n; l++)
				{
					if(left[l] <= u && right[l] > v)
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
			qflow[0] = 1<<30;
			from[0] = -1;
			used[0] = 1;
			for(i=0, j=1; i<j; i++)
			{
				now = queue[i];
				f = qflow[i];
				if(!now || now > n)
				{
					if(map[now][t])
					{
						queue[j] = t;
						qflow[j] = min(map[now][t], f);
						from[j] = i;
						break;
					}
					for(k=1; k<=n; k++)
					{
						if(!used[k] && map[now][k])
						{
							used[k] = 1;
							queue[j] = k;
							qflow[j] = min(map[now][k], f);
							from[j++] = i;
						}
					}
				}
				else
				{
					for(k=n+1; k<=t; k++)
					{
						if(!used[k] && map[now][k])
						{
							used[k] = 1;
							queue[j] = k;
							qflow[j] = min(map[now][k], f);
							from[j++] = i;
						}
					}
				}
			}
			if(i == j)
			{
				break;
			}
			else
			{
				f = qflow[j];
				for(; from[j]!=-1; j=from[j])
				{
					u = queue[from[j]];
					v = queue[j];
					map[u][v] -= f;
					map[v][u] += f;
				}
			}
		}
		for(i=1; i<=n; i++)
		{
			if(map[0][i])
			{
				break;
			}
		}
		if(i > n)
		{
			printf("FEASIBLE\n");
		}
		else
		{
			printf("NO WAY\n");
		}
	}
	return 0;
}
