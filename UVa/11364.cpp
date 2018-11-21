#include <stdio.h>

int main()
{
	int count, n, i, loc, min, max;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, min=200, max=-1; i<n; i++)
		{
			scanf("%d", &loc);
			if(loc < min)
			{
				min = loc;
			}
			if(loc > max)
			{
				max = loc;
			}
		}
		printf("%d\n", (max-min)<<1);
	}
	return 0;
}
