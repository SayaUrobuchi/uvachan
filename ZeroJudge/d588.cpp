#include <stdio.h>

int main()
{
	int count, n, i, res, a, b;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, res=-2147483647; i<n; i++)
		{
			scanf("%*d%*d%d%*d%*d%d", &a, &b);
			if(a>res)
			{
				res = a;
			}
			if(b>res)
			{
				res = b;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
