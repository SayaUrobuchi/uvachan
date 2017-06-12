#include <stdio.h>
#include <string.h>

int ans, num[10005], map[10005][10005], value[10005], count[10005], root[10005];

void travel(int now)
{
	int i, t;
	/*printf("now %d\n", now);*/
	for(i=0, count[now]=1; i<num[now]; i++)
	{
		travel(t=map[now][i]);
		if(value[t] < count[t])
		{
			ans += count[t] - value[t];
		}
		else
		{
			ans += value[t] - count[t];
		}
		value[now] += value[t];
		count[now] += count[t];
	}
	/*printf("XDD %d %d\n", now, count[now]);*/
}

int main()
{
	int n, i, j, node;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(root, 0, sizeof(root));
		memset(count, 0, sizeof(count));
		for(i=0; i<n; i++)
		{
			scanf("%d", &node);
			scanf("%d%d", &value[node], &num[node]);
			for(j=0; j<num[node]; j++)
			{
				scanf("%d", &map[node][j]);
				root[map[node][j]] = 1;
			}
		}
		for(i=1; i<=n; i++)
		{
			if(root[i] == 0)
			{
				ans = 0;
				travel(i);
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
