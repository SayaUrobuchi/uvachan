#include <stdio.h>

int main()
{
	int count, cas, n, i, p, up, down, las;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &las);
		up = 0;
		down = 0;
		for(i=1; i<n; i++)
		{
			scanf("%d", &p);
			if(p > las)
			{
				up++;
			}
			else if(p < las)
			{
				down++;
			}
			las = p;
		}
		printf("Case %d: %d %d\n", ++cas, up, down);
	}
	return 0;
}
