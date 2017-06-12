#include <stdio.h>
#include <string.h>

int map[1000][1000], dis[1000], ans[1000], n;
char chk[1000];

int recursion(int now)
{
	int i;
	if(chk[now])
	{
		return ans[now];
	}
	ans[now] = 0;
	for(i=0; i<n; i++)
	{
		if(map[now][i] && dis[now] > dis[i])
		{
			ans[now] += recursion(i);
		}
	}
	chk[now] = 1;
	return ans[now];
}

int main()
{
	int m, i, j, k, min, temp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		memset(chk, 1, sizeof(chk));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i-1][j-1] = map[j-1][i-1] = k;
		}
		for(i=0; i<n; i++)
		{
			dis[i] = map[1][i];
		}
		chk[1] = 0;
		for(i=1; i<n; i++)
		{
			for(j=0, min=2147483647; j<n; j++)
			{
				if(chk[j] && dis[j] && dis[j] < min)
				{
					min = dis[j];
					temp = j;
				}
			}
			chk[temp] = 0;
			for(j=0; j<n; j++)
			{
				if(chk[j] && map[temp][j] && (dis[j] > dis[temp] + map[temp][j] || !dis[j]))
				{
					dis[j] = dis[temp] + map[temp][j];
				}
			}
		}
		/*for(i=0; i<n; i++)
		{
			printf("dis %d: %d\n", i, dis[i]);
		}*/
		memset(chk, 0, sizeof(chk));
		ans[1] = 1;
		chk[1] = 1;
		printf("%d\n", recursion(0));
		/*for(i=0; i<n; i++)
		{
			printf("%d: %d %d\n", i, chk[i], ans[i]);
		}*/
	}
	return 0;
}
