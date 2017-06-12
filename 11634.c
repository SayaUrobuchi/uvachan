#include <stdio.h>
#include <string.h>

int tbl[10000];

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		tbl[n] = 1;
		for(i=0; ; i++)
		{
			n *= n;
			n = n / 100;
			n = n % 10000;
			if(tbl[n])
			{
				break;
			}
			tbl[n] = 1;
		}
		printf("%d\n", i+1);
	}
	return 0;
}
