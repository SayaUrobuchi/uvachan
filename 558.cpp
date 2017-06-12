#include <stdio.h>
#include <string.h>

int s[2001], e[2001], l[2001];
int dis[1001];

int main()
{
	int count, n, m, i, j, start, end, length;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &s[i], &e[i], &l[i]);
		}
		memset(dis, 1, sizeof(dis));
		dis[0] = 0;
		for(i=1; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				start = s[j];
				end = e[j];
				length = l[j];
				if(dis[start] + length < dis[end])
				{
					dis[end] = dis[start] + length;
				}
			}
		}
		for(j=0; j<m; j++)
		{
			start = s[j];
			end = e[j];
			length = l[j];
			if(dis[start] + length < dis[end])
			{
				break;
			}
		}
		if(j == m)
		{
			printf("not possible\n");
		}
		else
		{
			printf("possible\n");
		}
	}
	return 0;
}
