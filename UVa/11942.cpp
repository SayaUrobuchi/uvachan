#include <stdio.h>

int ary[15];

int main()
{
	int gg, i, count, dif, t;
	printf("Lumberjacks:\n");
	scanf("%d", &count);
	while(count--)
	{
		gg = 0;
		for(i=0; i<10; i++)
		{
			scanf("%d", &ary[i]);
			if(i == 1)
			{
				dif = ary[i]-ary[i-1];
			}
			else if(i)
			{
				t = ary[i]-ary[i-1];
				if((t < 0 && dif > 0) || (t > 0 && dif < 0))
				{
					gg = 1;
				}
			}
		}
		if(gg)
		{
			printf("Unordered\n");
		}
		else
		{
			printf("Ordered\n");
		}
	}
	return 0;
}
