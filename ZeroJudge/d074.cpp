#include <stdio.h>

int main()
{
	int n, i, mx, m;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, mx=-2147483647; i<n; i++)
		{
			scanf("%d", &m);
			if(m > mx)
			{
				mx = m;
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}
