#include <stdio.h>
#include <string.h>

int px[5005], py[5005], dx[5005], dy[5005], cc[5005];

int main()
{
	int n, m, i, c, x1, x2, y1, y2, ans, left, right, center;
	c = 0;
	while(scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2) == 6)
	{
		px[0] = x1;
		py[0] = y1;
		dx[0] = 0;
		dy[0] = y2 - y1;
		px[n+1] = x2;
		py[n+1] = y2;
		dx[n+1] = 0;
		dy[n+1] = y1 - y2;
		memset(cc, 0, sizeof(cc));
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &x1);
			py[i] = py[0];
			dx[i] = x1 - px[i];
			dy[i] = py[n+1] - py[i];
		}
		while(m--)
		{
			scanf("%d%d", &x1, &y1);
			for(ans=0, left=0, right=n; left<=right; )
			{
				center = ((left + right) >> 1);
				if(x1 > px[center] + (double)dx[center] * (y1-py[center]) / dy[center])
				{
					ans = center;
					left = center + 1;
				}
				else
				{
					right = center - 1;
				}
			}
			cc[ans]++;
		}
		if(c)
		{
			printf("\n");
		}
		c = 1;
		for(i=0; i<=n; i++)
		{
			printf("%d: %d\n", i, cc[i]);
		}
	}
	return 0;
}
