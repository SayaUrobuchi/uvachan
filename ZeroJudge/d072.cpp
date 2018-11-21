#include <stdio.h>

int main()
{
	int cas, n, count;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n % 4 == 0 && (n % 100 || n % 400 == 0))
		{
			printf("Case %d: a leap year\n", ++cas);
		}
		else
		{
			printf("Case %d: a normal year\n", ++cas);
		}
	}
	return 0;
}
