#include <stdio.h>
#include <string.h>

int tbl[1000005], ary[305];

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		memset(tbl, 0, sizeof(tbl));
		for(i=n; ; i++)
		{
			for(j=0; j<n; j++)
			{
				if(tbl[ary[j]%i] == i)
				{
					break;
				}
				tbl[ary[j]%i] = i;
			}
			if(j == n)
			{
				break;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
