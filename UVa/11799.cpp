#include <stdio.h>

int main()
{
	int count, n, i, p, mx, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, mx=-2147483647; i<n; i++)
		{
			scanf("%d", &p);
			if(p > mx)
			{
				mx = p;
			}
		}
		printf("Case %d: %d\n", ++cas, mx);
	}
	return 0;
}
