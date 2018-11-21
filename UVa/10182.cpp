#include <stdio.h>

int six[130], way[6][2]={{-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};

int bisearch(int n, int left, int right)
{
	int center, tmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(six[center] == n)
	{
		return center;
	}
	else if(six[center] > n)
	{
		tmp = bisearch(n, left, center-1);
		if(tmp == -1)
		{
			return center-1;
		}
		return tmp;
	}
	else
	{
		tmp = bisearch(n, center+1, right);
		if(tmp == -1)
		{
			return center;
		}
		return tmp;
	}
}

int main()
{
	int n, i, j, res, x, y;
	six[1] = 2;
	for(i=2, j=6; i<130; i++)
	{
		six[i] = six[i-1] + j;
		j += 6;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 1)
		{
			printf("0 0\n");
		}
		else
		{
			res = bisearch(n, 0, 129);
			x = res-1;
			y = 1;
			for(i=six[res], j=0; i<n; i++)
			{
				if(j == 1 || j == 4)
				{
					if(x == res || x == -res)
					{
						j++;
					}
				}
				else if(j == 2 || j == 5)
				{
					if(!y)
					{
						j++;
					}
				}
				else
				{
					if(y == res || y == -res)
					{
						j++;
					}
				}
				x += way[j][0];
				y += way[j][1];
			}
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}
