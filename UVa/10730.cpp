#include <stdio.h>

int ary[10000];

int main()
{
	int n, i, j, in, tmp, loc, loc2, loc3;
	char buf;
	while(scanf("%d%c", &n, &buf) == 2)
	{
		if(!n) break;
		for(i=0; i<n; i++)
		{
			scanf("%d", &in);
			ary[in] = i;
		}
		tmp = n / 2;
		for(i=0; i<n; i++)
		{
			loc = i;
			for(j=1; i+j+j<n; j++)
			{
				loc2 = i + j;
				loc3 = i + j + j;
				if(ary[loc] < ary[loc2] && ary[loc2] < ary[loc3])
				{
					break;
				}
				if(i - j - j > -1)
				{
					loc2 = i - j;
					loc3 = i - j - j;
					if(ary[loc] < ary[loc2] && ary[loc2] < ary[loc3])
					{
						break;
					}
				}
			}
			if(i + j + j < n)
			{
				break;
			}
		}
		if(i < n)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
