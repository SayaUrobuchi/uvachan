#include <stdio.h>

int map[1100000];

int main()
{
	int count, n, i, j, k, l, c, t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, l=n*n, c=0; i<n; i++)
		{
			for(j=0; j<l; j++)
			{
				scanf("%d", &map[t=i*l+j]);
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
