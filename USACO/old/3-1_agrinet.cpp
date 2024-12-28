/*
	ID: sa072682
	LANG: C
	TASK: agrinet
*/
#include <stdio.h>

int map[100][100], dis[100];

int main()
{
	int n, i, j, cost, min, temp;
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for(i=1; i<n; i++)
	{
		dis[i] = map[0][i];
	}
	for(i=1, cost=0; i<n; i++)
	{
		for(j=1, min=2147483647; j<n; j++)
		{
			if(dis[j] != -1 && dis[j] < min)
			{
				min = dis[j];
				temp = j;
			}
		}
		cost += dis[temp];
		dis[temp] = -1;
		for(j=1; j<n; j++)
		{
			if(dis[j] > map[temp][j])
			{
				dis[j] = map[temp][j];
			}
		}
	}
	printf("%d\n", cost);
	scanf(" ");
	return 0;
}
