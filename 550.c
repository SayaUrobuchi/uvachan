#include <stdio.h>

int main()
{
	int n, i, c, t, b, d, f;
	while(scanf("%d%d%d", &b, &d, &f) == 3)
	{
		for(i=0, c=0, t=d, n=0; ; i++)
		{
			n = t * f + c;
			if(n == d)
			{
				break;
			}
			c = n / b;
			t = n %= b;
		}
		printf("%d\n", i+1);
	}
	return 0;
}

