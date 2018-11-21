#include <stdio.h>
#include <string.h>

int dis[505], used[505];
char str[505][5];

int ab(int t)
{
	return t<0 ? -t : t;
}

int calc(int p, int q)
{
	int i, res, t;
	for(i=0, res=0; i<4; i++)
	{
		t = ab(str[p][i]-str[q][i]);
		if(t > 5)
		{
			t = 10-t;
		}
		res += t;
	}
	return res;
}

int main()
{
	int count, n, i, j, ans, mi, temp, dd;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%s", str[i]);
		}
		strcpy(str[0], "0000");
		memset(dis, 1, sizeof(dis));
		memset(used, 0, sizeof(used));
		dis[0] = 0;
		for(i=0, ans=0; i<=n; i++)
		{
			for(j=0, mi=2147483647; j<=n; j++)
			{
				if(used[j] == 0 && mi > dis[j])
				{
					mi = dis[j];
					temp = j;
				}
			}
			used[temp] = 1;
			ans += dis[temp];
			for(j=0; j<=n; j++)
			{
				if(used[j] == 0)
				{
					dd = calc(temp, j);
					if(dd < dis[j] || i == 1)
					{
						dis[j] = dd;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
