#include <stdio.h>

int c, map[1100000], bst[1100000];

void bisearch(int left, int right, int target)
{
	int center;
	center = ((left+right) >> 1);
	if(center == target)
	{
		c += bst[center];
		bst[center]++;
	}
	else if(center > target)
	{
		bisearch(left, center-1, target);
		c += bst[center];
	}
	else
	{
		bisearch(center+1, right, target);
		bst[center]++;
	}
}

int main()
{
	int count, n, m, i, j, k, l, p, q, t, now, temp, center;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, m=0, l=n*n, c=0; i<n; i++, m+=l)
		{
			for(j=0; j<n; j++)
			{
				for(k=0; k<n; k++)
				{
					scanf("%d", &map[t=j*l+i*n+k]);
					bst[t+1] = 0;
				}
			}
		}
		for(i=0, j=l*n, t=0; i<j; i++)
		{
			/*for(k=1; k<j; k++)
			{
				printf("%d: %d\n", k, bst[k]);
			}*/
			now = map[i];
			if(now)
			{
				bisearch(1, j-1, now);
				/*printf("%d\n", c);*/
			}
			else if(n % 2 == 0)
			{
				/*printf("%d %d %d\n", i, i/l+1, (i%l)/n+1);*/
				c += i/l+1 + (i%l)/n+1;
			}
		}
		/*for(i=1; i<j; i++)
		{
			printf("%d: %d\n", i, bst[i]);
		}*/
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
