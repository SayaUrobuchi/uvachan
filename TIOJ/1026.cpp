#include <stdio.h>

int main()
{
	int n, l, str[35];
	while(scanf("%d", &n) == 1)
	{
		l = 0;
		while(n)
		{
			str[l++] = n % 2;
			n /= 2;
		}
		printf("%d\n", l);
		for(n=1; n<l; n++)
		{
			if(str[n])
			{
				printf("+");
			}
			else
			{
				printf("-");
			}
		}
		printf("+\n");
	}
	return 0;
}

