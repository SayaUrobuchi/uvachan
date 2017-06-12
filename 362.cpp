#include <stdio.h>

int main()
{
	int cas, n, total, pre, next, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("Output for data set %d, %d bytes:\n", ++cas, n);
		total = 0;
		pre = 0;
		next = n;
		while(scanf("%d", &temp) == 1)
		{
			total++;
			next -= temp;
			pre += temp;
			if(!(total % 5))
			{
				if(pre)
				{
					printf("   Time remaining: %d seconds\n", 5*next/pre+1-!((5*next)%pre));
				}
				else
				{
					printf("   Time remaining: stalled\n");
				}
				pre = 0;
			}
			if(!next)
			{
				break;
			}
		}
		printf("Total time: %d seconds\n\n", total);
	}
	return 0;
}
