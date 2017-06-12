#include <stdio.h>

int main()
{
	int cas, count, n, i, s, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("Case #%d: %d", ++cas, n);
		for(i=2+n%2, s=1+n%2, c=0; ; i+=s)
		{
			if(!(n % i))
			{
				printf(" = %d * %d", i, n / i);
				c++;
				if(c == 2)
				{
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
