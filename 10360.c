#include <stdio.h>
#include <string.h>

int map[1025][1025], tbl[1025];

int main()
{
	int count, d, n, i, j, sum, res, x, y, z;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &d, &n);
		d = (d << 1) + 1;
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			map[x][y] = z;
		}
		for(i=0, sum=0; i<d; i++)
		{
			tbl[i] = 0;
			for(j=0; j<d; j++)
			{
				tbl[i] += map[j][i];
			}
			sum += tbl[i];
		}
		for(res=sum, x=d/2, y=d/2; i<1025; i++)
		{
			tbl[i] = 0;
			for(j=0; j<d; j++)
			{
				tbl[i] += map[j][i];
			}
			sum -= tbl[i-d];
			sum += tbl[i];
			if(sum > res)
			{
				res = sum;
				x = d/2;
				y = i;
			}
		}
		for(i=d; i<1025; i++)
		{
			for(j=0, sum=0; j<d; j++)
			{
				tbl[j] -= map[i-d][j];
				tbl[j] += map[i][j];
				sum += tbl[j];
			}
			if(sum > res)
			{
				res = sum;
				x = i - d/2;
				y = d / 2;
			}
			for(; j<1025; j++)
			{
				tbl[j] -= map[i-d][j];
				tbl[j] += map[i][j];
				sum -= tbl[j-d];
				sum += tbl[j];
				if(sum > res)
				{
					res = sum;
					x = i - d/2;
					y = j - d/2;
				}
			}
		}
		printf("%d %d %d\n", x, y, res);
	}
	return 0;
}

