#include <stdio.h>

int ary[13][4];
char map[13][13];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

char connect(int p, int q)
{
	int *a, *b, x1, x2, y1, y2, r1, r2;
	a = ary[p];
	b = ary[q];
	x1 = a[0] - b[0];
	x2 = a[0] - a[2];
	y1 = a[1] - b[1];
	y2 = a[1] - a[3];
	r1 = x1 * y2 - x2 * y1;
	x1 = a[0] - b[2];
	y1 = a[1] - b[3];
	r2 = x1 * y2 - x2 * y1;
	if(r1 * r2 < 0 || ((r1 || r2) && !(r1 * r2)))
	{
		a = ary[q];
		b = ary[p];
		x1 = a[0] - b[0];
		x2 = a[0] - a[2];
		y1 = a[1] - b[1];
		y2 = a[1] - a[3];
		r1 = x1 * y2 - x2 * y1;
		x1 = a[0] - b[2];
		y1 = a[1] - b[3];
		r2 = x1 * y2 - x2 * y1;
		if(r1 * r2 < 0 || ((r1 || r2) && !(r1 * r2)))
		{
			return 1;
		}
	}
	else if(!r1 && !r2)
	{
		a = ary[q];
		b = ary[p];
		x1 = a[0] - b[0];
		x2 = a[0] - a[2];
		y1 = a[1] - b[1];
		y2 = a[1] - a[3];
		r1 = x1 * y2 - x2 * y1;
		x1 = a[0] - b[2];
		y1 = a[1] - b[3];
		r2 = x1 * y2 - x2 * y1;
		if(!r1 && !r2)
		{
			if(a[0] == a[2])
			{
				if(max(a[1], a[3]) >= min(b[1], b[3]) && min(a[1], a[3]) <= max(b[1], b[3]))
				{
					return 1;
				}
				else if(max(b[1], b[3]) >= min(a[1], a[3]) && min(b[1], b[3]) <= max(a[1], a[3]))
				{
					return 1;
				}
			}
			else
			{
				if(max(a[0], a[2]) >= min(b[0], b[2]) && min(a[0], a[2]) <= max(b[0], b[2]))
				{
					return 1;
				}
				else if(max(b[0], b[2]) >= min(a[0], a[2]) && min(b[0], b[2]) <= max(a[0], a[2]))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &ary[i][0], &ary[i][1], &ary[i][2], &ary[i][3]);
			for(j=0; j<i; j++)
			{
				map[i][j] = map[j][i] = connect(i, j);
			}
			map[i][i] = 1;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							map[i][j] = 1;
						}
					}
				}
			}
		}
		while(scanf("%d%d", &i, &j) == 2)
		{
			if(!i && !j)
			{
				break;
			}
			if(map[i-1][j-1])
			{
				printf("CONNECTED\n");
			}
			else
			{
				printf("NOT CONNECTED\n");
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
