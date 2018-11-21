#include <stdio.h>
#include <string.h>

int s, t;
int from[1000];
int map[1000][1000];
int dis[1000];
int used[1000];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

void backtracking(int now, int f)
{
	int last;
	/*printf("%d\n", now);*/
	last = from[now];
	if(last != s)
	{
		backtracking(last, f);
	}
	map[last][now] -= f;
	map[now][last] += f;
}

int main()
{
	int n, m, i, j, maxf, maxnum, temp;
	while(scanf("%d", &n) == 1)
	{
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		s = 0;
		t = (n<<1) + 1;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &map[i][n+i]);
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i+n][j] = 1000000000;
			used[i] |= 1;
			used[j] |= 2;
		}
		for(i=1; i<=n; i++)
		{
			if(!(used[i] & 1))
			{
				map[n+i][t] = 1000000000;
			}
			if(!(used[i] & 2))
			{
				map[0][i] = 1000000000;
			}
		}
		for(maxf=0; ; )
		{
			memset(used, 0, sizeof(used));
			memset(dis, 0, sizeof(dis));
			used[s] = 1;
			for(i=1; i<=n; i++)
			{
				if(map[s][i])
				{
					dis[i] = map[s][i];
					from[i] = s;
				}
			}
			for(; ; )
			{
				for(i=1, maxnum=0, temp=0; i<=t; i++)
				{
					if(!used[i] && dis[i] > maxnum)
					{
						maxnum = dis[i];
						temp = i;
					}
				}
				used[temp] = 1;
				if(maxnum == 0 || temp == t)
				{
					break;
				}
				for(i=1; i<=t; i++)
				{
					if(!used[i] && dis[i] < min(dis[temp], map[temp][i]))
					{
						dis[i] = min(dis[temp], map[temp][i]);
						from[i] = temp;
					}
				}
			}
			if(used[t])
			{
				/*printf("F %d\n", dis[t]);*/
				maxf += dis[t];
				backtracking(t, dis[t]);
			}
			else
			{
				break;
			}
		}
		printf("%d\n", maxf);
	}
	return 0;
}
