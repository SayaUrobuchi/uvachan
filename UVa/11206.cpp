#include <stdio.h>
#include <string.h>

int ary[20], c[4], max, n;
char chk[20], map[20][20], num[20];

void dfs(int now, int cost)
{
	int i, j, k, tmp;
	char tbl[4];
	if(now == n)
	{
		if(cost > max)
		{
			max = cost;
		}
		return;
	}
	memset(tbl, 1, sizeof(tbl));
	for(i=0, j=num[now]; i<j; i++)
	{
		if(chk[map[now][i]])
		{
			tbl[ary[map[now][i]]] = 0;
		}
	}
	for(i=0; i<4; i++)
	{
		if(tbl[i])
		{
			ary[now] = i;
			chk[now] = 1;
			for(j=0, k=num[now], tmp=0; j<k; j++)
			{
				if(chk[map[now][j]])
				{
					tmp += (c[ary[now]] - c[ary[map[now][j]]]) * (c[ary[now]] - c[ary[map[now][j]]]);
				}
			}
			dfs(now+1, cost+tmp);
			chk[now] = 0;
		}
	}
}

int main()
{
	int m, i, j;
	memset(chk, 0, sizeof(chk));
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		memset(num, 0, sizeof(num));
		scanf("%d%d%d%d%d", &m, &c[0], &c[1], &c[2], &c[3]);
		while(m--)
		{
			scanf("%d%d", &i, &j);
			i--;
			j--;
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		max = 0;
		dfs(0, 0);
		printf("%d\n", max);
	}
	return 0;
}
