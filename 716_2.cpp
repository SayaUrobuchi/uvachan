#include <stdio.h>

int map[1100000];

int main()
{
	int count, n, m, i, j, k, l, c, t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, m=0, l=n*n, c=0; i<n; i++, m+=l)
		{
			for(j=0, t=m; j<l; j++, t++)
			{
				scanf("%d", &map[t]);
				if(map[t])
				{
					for(k=0; k<t; k++)
					{
						if(map[k] > map[t])
						{
							c++;
						}
					}
				}
				else if(n % 2 == 0)
				{
					c += i + j/n;
				}
			}
		}
		if(c % 2)
		{
			printf("Puzzle is unsolvable.\n");
		}
		else
		{
			printf("Puzzle can be solved.\n");
		}
	}
	return 0;
}
