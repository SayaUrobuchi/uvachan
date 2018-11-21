#include <stdio.h>
#include <string.h>

int mu1[105], mu2[105], mode1[105], mode2[105], used2[1005], m1[1005], m2[1005], used[1005];

int find(int);

int match1(int from, int now)
{
	mu1[now] = 1;
	if(mode1[now] == -1)
	{
		mode1[now] = from;
		return 1;
	}
	if(find(mode1[now]))
	{
		mode1[now] = from;
		return 1;
	}
	return 0;
}

int match2(int from, int now)
{
	mu2[now] = 1;
	if(mode2[now] == -1)
	{
		mode2[now] = from;
		return 1;
	}
	if(find(mode2[now]))
	{
		mode2[now] = from;
		return 1;
	}
	return 0;
}

int find(int now)
{
	used2[now] = 1;
	if(mu1[m1[now]] == 0 && match1(now, m1[now]))
	{
		return 1;
	}
	if(mu2[m2[now]] == 0 && match2(now, m2[now]))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int n, m, k, i, j, l, c;
	while(scanf("%d%d%d", &n, &m, &k) == 3)
	{
		for(i=0; i<k; i++)
		{
			scanf("%d", &j);
			scanf("%d%d", &m1[j], &m2[j]);
		}
		memset(used, 0, sizeof(used));
		for(j=0, c=0, i=0; c<k; j++)
		{
			memset(mode1, -1, sizeof(mode1));
			memset(mode2, -1, sizeof(mode2));
			memset(used2, 0, sizeof(used2));
			memset(mu1, 0, sizeof(mu1));
			memset(mu2, 0, sizeof(mu2));
			for(; i<k; i++)
			{
				for(l=1; l<=n; l++)
				{
					printf("mode1: %d %d\n", l, mode1[l]);
				}
				for(l=1; l<=m; l++)
				{
					printf("mode2: %d %d\n", l, mode2[l]);
				}
				if(used[i] == 0)
				{
					c += (used[i] = find(i));
					printf("%d: %d\n", i, used[i]);
					if(used[i] == 0)
					{
						break;
					}
				}
			}
		}
		printf("%d\n", j);
	}
	return 0;
}
