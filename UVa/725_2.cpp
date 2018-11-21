#include <stdio.h>
#include <string.h>

int tbl[10];

int chk(int now)
{
	int i, temp;
	for(i=0; i<5; i++, now/=10)
	{
		if(tbl[temp=now % 10])
		{
			return 0;
		}
		tbl[temp] = 1;
	}
	return 1;
}

int main()
{
	int cas, n, i, temp, c;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=n*1234, temp=1234, c=0; i<100000; i+=n, temp++)
		{
			memset(tbl, 0, sizeof(tbl));
			if(chk(i) && chk(temp))
			{
				printf("%05d / %05d = %d\n", i, temp, n);
				c++;
			}
		}
		if(!c)
		{
			printf("There are no solutions for %d.\n", n);
		}
	}
	return 0;
}
