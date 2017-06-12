#include <stdio.h>

int map[1100000];

int main()
{
	int count, n, m, i, j, k, l, p, q, c, t, now, temp, center;
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
					scanf("%d", &map[j*l+i*n+k]);
				}
			}
		}
		for(i=0, j=l*n, t=0; i<j; i++)
		{
			now = map[i];
			if(now)
			{
				for(p=0, q=t-1, temp=t; p<=q; )
				{
					center = ((p+q) >> 1);
					if(map[center] < now)
					{
						q = center - 1;
						temp = center;
					}
					else
					{
						p = center + 1;
					}
				}
				c += temp;
				/*printf("%d: %d\n", now, temp);*/
				for(k=t++; k>temp; map[k]=map[k-1], k--);
				map[temp] = now;
			}
			else if(n % 2 == 0)
			{
				/*printf("%d %d %d\n", i, i/l+1, (i%l)/n+1);*/
				c += i/l+1 + (i%l)/n+1;
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
