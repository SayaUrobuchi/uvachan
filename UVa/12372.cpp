#include <stdio.h>

int main()
{
	int count, cas, a, b, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a <= 20 && b <= 20 && c <= 20)
		{
			printf("Case %d: good\n", ++cas);
		}
		else
		{
			printf("Case %d: bad\n", ++cas);
		}
	}
	return 0;
}
