#include <stdio.h>

int main()
{
	int cas, count, m, i, j, in, cost[36], list[36], lnum, tmp, min, spend;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<36; i++)
		{
			scanf("%d", &cost[i]);
		}
		scanf("%d", &m);
		printf("Case %d:\n", ++cas);
		while(m--)
		{
			scanf("%d", &in);
			min = -1;
			for(i=2; i<37; i++)
			{
				spend = 0;
				if(!in)
				{
					spend += cost[0];
				}
				else
				{
					tmp = in;
					while(tmp)
					{
						spend += cost[tmp % i];
						tmp /= i;
					}
				}
				if(spend < min || min == -1)
				{
					min = spend;
					lnum = 1;
					list[0] = i;
				}
				else if(spend == min)
				{
					list[lnum++] = i;
				}
			}
			printf("Cheapest base(s) for number %d:", in);
			for(i=0; i<lnum; i++)
			{
				printf(" %d", list[i]);
			}
			printf("\n");
		}
		if(count) printf("\n");
	}
	return 0;
}