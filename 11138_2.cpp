#include <stdio.h>
#include <string.h>

int n, m;
int match[505];
int map[505][505];
int bused[505], nused[505];

int fill(int);

int select(int now)
{
	if(!match[now])
	{
		return 1;
	}
	return !bused[match[now]] && fill(match[now]);
}

int fill(int now)
{
	int i;
	bused[now] = 1;
	for(i=1; i<=m; i++)
	{
		if(map[now][i] && !nused[i])
		{
			nused[i] = 1;
			if(select(i))
			{
				match[i] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, count, i, j, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(match, 0, sizeof(match));
		for(i=1, c=0; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%d", &map[i][j]);
			}
			memset(bused, 0, sizeof(bused));
			memset(nused, 0, sizeof(nused));
			c += fill(i);
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", ++cas, c);
	}
	return 0;
}
