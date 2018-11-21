#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, ans, part, qnum;
int num[40];
int map[40][40];
int used[40], light[40], mark[40];
int queue[40];

int comp(const void *p, const void *q)
{
	return num[*(int*)q] - num[*(int*)p];
}

void getconn(int now)
{
	int i;
	mark[now] = 1;
	queue[qnum++] = now;
	for(i=0; i<num[now]; i++)
	{
		if(!mark[map[now][i]])
		{
			getconn(map[now][i]);
		}
	}
}

void dfs(int depth, int nodes)
{
	int i, now;
	if(nodes >= part)
	{
		return;
	}
	if(depth >= qnum)
	{
		part = nodes;
		return;
	}
	now = queue[depth];
	if(!used[now])
	{
		for(i=0; i<num[now]; i++)
		{
			if(used[map[now][i]])
			{
				break;
			}
		}
	}
	if(i < num[now] || used[now])
	{
		dfs(depth+1, nodes);
	}
	else
	{
		if(!used[now] && (qnum < 3 || num[now] > 1))
		{
			used[now] = 1;
			dfs(depth+1, nodes+1);
			used[now] = 0;
		}
		for(i=0; i<num[now]; i++)
		{
			if(!used[map[now][i]])
			{
				used[map[now][i]] = 1;
				dfs(depth+1, nodes+1);
				used[map[now][i]] = 0;
			}
		}
	}
}

int main()
{
	int m, i, j, k;
	/*freopen("1.txt", "w", stdout);*/
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		ans = 0;
		memset(used, 0, sizeof(used));
		memset(mark, 0, sizeof(mark));
		memset(light, 0, sizeof(light));
		for(i=1; i<=n; i++)
		{
			if(!mark[i])
			{
				qnum = 0;
				getconn(i);
				qsort(queue, qnum, sizeof(int), comp);
				part = 1;
				light[queue[0]] = 1;
				for(j=1; j<qnum; j++)
				{
					for(k=0; k<num[queue[j]]; k++)
					{
						if(light[map[queue[j]][k]])
						{
							break;
						}
					}
					if(k == num[queue[j]])
					{
						part++;
						light[queue[j]] = 1;
					}
				}
				dfs(0, 0);
				ans += part;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
