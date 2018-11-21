#include <stdio.h>

int ary[100005];

int main()
{
	int n, m, i, j, p, q, c, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for(p=-2147483647, q=2147483647; p<=q; )
		{
			c = ((p+q) >> 1);
			for(i=0, j=0; i<n; i++)
			{
				if(ary[i] >= c)
				{
					j++;
					if(j >= m)
					{
						break;
					}
				}
				else
				{
					j = 0;
				}
			}
			if(i < n)
			{
				p = c+1;
				temp = c;
			}
			else
			{
				q = c-1;
			}
		}
		printf("%d\n", temp);
	}
	return 0;
}
