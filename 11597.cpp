#include <stdio.h>

int main()
{
	int cas, n;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		printf("Case %d: %d\n", ++cas, ((n*(n-1))>>1) / (n-1));
	}
	return 0;
}
