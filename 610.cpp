#include <stdio.h>
#include <string.h>

int map[1001][5], num[1001];
int used[5001], chk[1001];
int start[5001], end[5001];
int list[5001];
int parent[1001];

int getparent(int now)
{
	if(parent[now] == -1)
	{
		return now;
	}
	return parent[now] = getparent(parent[now]);
}

int getanother(int now, int edge)
{
	if(now == start[edge])
	{
		return end[edge];
	}
	return start[edge];
}

int dfs(int now, int depth)
{
	int i, j, temp;
	for(i=0; i<num[now]; i++)
	{
		if(!used[map[now][i]])
		{
			used[map[now][i]] = 1;
			temp = getanother(now, map[now][i]);
			printf("%d %d\n", now, temp);
			list[depth] = now;
			if(!chk[temp])
			{
				chk[now] = depth + 1;
				dfs(temp, depth+1);
				if(getparent(now) != getparent(temp))
				{
					printf("%d %d\n", temp, now);
					parent[getparent(now)] = getparent(temp);
				}
				chk[now] = 0;
			}
			else
			{
				for(j=chk[temp]; j<=depth; j++)
				{
					if(getparent(list[j]) != getparent(list[chk[temp]-1]))
					{
						parent[getparent(list[j])] = getparent(list[chk[temp]-1]);
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int cas, n, m, i, j, temp;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &start[i], &end[i]);
			map[start[i]][num[start[i]]++] = i;
			map[end[i]][num[end[i]]++] = i;
		}
		printf("%d\n\n", ++cas);
		for(i=1; i<=n; i++)
		{
			parent[i] = -1;
		}
		memset(used, 0, sizeof(used));
		memset(chk, 0, sizeof(chk));
		dfs(1, 0);
		printf("#\n");
	}
	return 0;
}
