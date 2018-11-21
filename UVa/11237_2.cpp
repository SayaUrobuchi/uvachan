#include <stdio.h>
#include <string.h>

int ary[100001], nei[100001];

int main()
{
	int n, c, i, j, sum;
	while(scanf("%d%d", &c, &n) == 2)
	{
		if(!c && !n)
		{
			break;
		}
		memset(ary, 0, 4 * c);
		ary[0] = 1;
		for(i=0, sum=0; ; i++)
		{
			scanf("%d", &nei[i]);
			sum += nei[i];
			sum %= c;
			if(ary[sum])
			{
				for(j=ary[sum]-1; j<i; j++)
				{
					printf("%d ", nei[j]);
				}
				printf("%d\n", nei[j]);
				break;
			}
			else
			{
				ary[sum] = i + 2;
			}
		}
		for(i++; i<n; i++)
		{
			scanf("%d", &c);
		}
	}
	return 0;
}
