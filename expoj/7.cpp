#include <stdio.h>

char buf0[4096], buf1[4096];

int main()
{
	int count, n, m, a, b, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%s%s", &n, &m, buf0, buf1);
		for(i=0; i<n; i+=2)
		{
			sscanf(buf0+i, "%2X", &a);
			sscanf(buf1+i, "%2X", &b);
			printf("%02X", a^b);
		}
		printf("\n");
	}
	return 0;
}
