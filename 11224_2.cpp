#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[9][2];

void swap(int* x, int* y)
{
	x[0] ^= y[0] ^= x[0] ^= y[0];
	x[1] ^= y[1] ^= x[1] ^= y[1];
}

int main()
{
	int cas, count, n, p, r, i, ans, rank, c, speed, m, d, s;
	char buf[9];
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &p, &r);
		n = 0;
		while(--p)
		{
			scanf("%d%s", &ary[n][0], buf);
			sscanf(buf, "%d:%d:%d", &m, &d, &s);
			ary[n][1] = m * 6000 + d * 100 + s;
			for(i=n-1; i>-1; i--)
			{
				if(ary[i][1] == ary[i+1][1])
				{
					if(ary[i][0] > ary[i+1][0])
					{
						swap(ary[i], ary[i+1]);
					}
					else
					{
						i = -1;
						break;
					}
				}
				else if(ary[i][1] > ary[i+1][1])
				{
					swap(ary[i], ary[i+1]);
				}
				else
				{
					i = -1;
					break;
				}
			}
			if(n < 8)
			{
				n++;
			}
		}
		for(i=1, ans=0, rank=0, c=ary[0][0]<r; i<8&&c<3; i++)
		{
			speed = ary[i-1][1];
			if(i == n)
			{
				rank = i;
				ans = c;
			}
			else if(speed == ary[i][1])
			{
				if(ary[i][0] > r && ary[i-1][0] < r)
				{
					rank = i;
					ans = c;
				}
			}
			else if(speed + 1 == ary[i][1])
			{
				if(ary[i-1][0] < r || ary[i][0] > r)
				{
					rank = i;
					ans = c;
				}
			}
			else
			{
				rank = i;
				ans = c;
			}
			if(ary[i][0] < r)
			{
				c++;
			}
		}
		printf("Case #%d:\nGustavo should be #%d during the qualification to achieve position #%d in the final.\n", ++cas, rank+1, ans+1);
	}
	return 0;
}
