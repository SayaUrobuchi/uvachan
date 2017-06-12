#include <stdio.h>

int cost[100], map[100][100], num[100], chk[100], queue[510000][2];

int main()
{
	int n, m, i, j, k, l, x, e, temp, ti, tj;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &cost[i], &m);
			chk[i] = 0;
			num[i] = 0;
			while(m--)
			{
				scanf("%d", &map[i][num[i]]);
				map[i][num[i]++]--;
			}
		}
		queue[0][0] = 0;
		queue[0][1] = 100;
		chk[0] = 100;
		for(i=0, j=1; i<j&&i<500000; i++)
		{
			x = queue[i][0];
			e = queue[i][1];
			for(k=0, l=num[x]; k<l; k++)
			{
				temp = map[x][k];
				if(e + cost[temp] > chk[temp])
				{
					chk[temp] = queue[j][1] = e + cost[temp];
					queue[j++][0] = temp;
					if(temp == n - 1)
					{
						break;
					}
				}
			}
			if(k < l)
			{
				break;
			}
		}
		if(i == j || i == 500000)
		{
			printf("hopeless\n");
		}
		else
		{
			printf("winnable\n");
		}
	}
	return 0;
}
