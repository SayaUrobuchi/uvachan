#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[1010][2];

int comp(const void *p, const void *q)
{
	if(((int*)p)[1] == ((int*)q)[1])
	{
		return ((int*)p)[0] - ((int*)q)[0];
	}
	else
	{
		return ((int*)p)[1] - ((int*)q)[1];
	}
}

int main()
{
	int cas, count, n, r, i, ans, rank, c, speed, m, d, s;
	char buf[100];
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &r);
  		for(i=0, n--; i<n; i++)
		{
			scanf("%d%s", &ary[i][0], buf);
			sscanf(buf, "%d:%d:%d", &m, &d, &s);
			ary[i][1] = m * 6000 + d * 100 + s;
		}
		qsort(ary, n, sizeof(ary[0]), comp);
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
