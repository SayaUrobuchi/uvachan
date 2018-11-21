#include <stdio.h>

int main()
{
	int count, cas, in, max, now;
	short left, right, tmp, i, n;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		max = -1;
		now = 0;
		tmp = 0;
		for(i=1; i<n; i++)
		{
			scanf("%d", &in);
			now += in;
			if(now < 0)
			{
        now = 0;
				tmp = i;
			}
			else
			{
        if(now > max)
				{
					max = now;
					left = tmp;
					right = i;
				}
				else if(now == max)
				{
					if(i - tmp > right - left)
					{
						left = tmp;
						right = i;
					}
				}
			}
		}
		if(max == -1) printf("Route %d has no nice parts\n", ++cas);
		else printf("The nicest part of route %d is between stops %d and %d\n", ++cas, left+1, right+1);
	}
	return 0;
}
