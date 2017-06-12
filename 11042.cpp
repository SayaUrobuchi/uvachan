#include <stdio.h>

int main()
{
	long c, d, ctmp, dtmp;
	int count, a, b, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &a, &b);
		c = a;
		d = b;
		for(i=1; ; i++)
		{
			if(!d)
			{
				printf("%d\n", i);
				break;
			}
			ctmp = a*c - b*d;
			dtmp = b*c + a*d;
			c = ctmp;
			d = dtmp;
			if(ctmp > 1073741824 || ctmp < -1073741824)
			{
				printf("TOO COMPLICATED\n");
				break;
			}
		}
	}
	return 0;
}
