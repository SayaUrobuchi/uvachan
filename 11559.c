#include <stdio.h>

int main()
{
	int people, budge, hotel, week, best, price, bed, i, j;
	while(scanf("%d%d%d%d", &people, &budge, &hotel, &week) == 4)
	{
		best = budge + 1;
		for(i=0; i<hotel; i++)
		{
			scanf("%d", &price);
			for(j=0; j<week; j++)
			{
				scanf("%d", &bed);
				if(bed >= people && price * people < best)
				{
					best = price * people;
				}
			}
		}
		if(best > budge)
		{
			printf("stay home\n");
		}
		else
		{
			printf("%d\n", best);
		}
	}
	return 0;
}

