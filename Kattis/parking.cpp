#include <stdio.h>
#include <string.h>

int cost[8], ary[128];

int main()
{
	int i, j, p, q, ans;
	while (scanf("%d%d%d", &cost[1], &cost[2], &cost[3]) == 3)
	{
		memset(ary, 0, sizeof(ary));
		cost[2] <<= 1;
		cost[3] *= 3;
		for (i=0; i<3; i++)
		{
			scanf("%d%d", &p, &q);
			for (j=p; j<q; j++)
			{
				ary[j]++;
			}
		}
		for (i=1, ans=0; i<=100; i++)
		{
			ans += cost[ary[i]];
		}
		printf("%d\n", ans);
	}
	return 0;
}
