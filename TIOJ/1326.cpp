#include <stdio.h>
#include <string.h>

int dis[1005], px[1005], py[1005], used[1005];

int ab(int now)
{
	return now < 0 ? -now : now;
}

int getdis(int p, int q)
{
	return (px[p]==px[q] || py[p]==py[q]) ? ab(px[p]-px[q])+ab(py[p]-py[q]) : 2147483647;
}

int main()
{
	int count, n, i, j, min, temp, res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		memset(used, 0, sizeof(used));
		used[0] = 1;
		for(i=1; i<n; i++)
		{
			dis[i] = getdis(0, i);
		}
		for(i=1, res=0; i<n; i++)
		{
			for(j=1, min=2147483647; j<n; j++)
			{
				if(used[j] == 0 && dis[j] < min)
				{
					min = dis[j];
					temp = j;
				}
			}
			used[temp] = 1;
			res += min;
			for(j=1; j<n; j++)
			{
				if(used[j] == 0 && (min=getdis(temp, j)) < dis[j])
				{
					dis[j] = min;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
