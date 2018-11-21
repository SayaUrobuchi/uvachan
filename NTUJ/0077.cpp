#include <stdio.h>

int main()
{
	int n, i, p, q, b, sum;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, p=200000, q=0, sum=0; i<n; i++)
		{
			scanf("%d", &b);
			sum += b;
			if(b < p)
			{
				p = b;
			}
			if(b > q)
			{
				q = b;
			}
		}
		printf("%d\n", (sum-p-q)/(n-2));
	}
	return 0;
}
