/*
	ID: sa072682
	LANG: C
	TASK: fence9
*/
#include <stdio.h>

int cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - y1 * x2;
}

int main()
{
	int n, m, p, i, j, max, min, ans, left, right, center;
	long long c, ct, cp;
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &p);
	ct = cross(n, m, 1, -1);
	cp = cross(n-p, m, -1-p, 0);
	for(i=1, ans=0; i<p||i<n; i++)
	{
		left = 1;
		right = m;
		max = 0;
		while(left <= right)
		{
			center = left + right;
			center /= 2;
			c = cross(n, m, i, center) * ct;
			if(c > 0)
			{
				c = cross(n-p, m, i-p, center) * cp;
				if(c > 0)
				{
					left = center + 1;
					if(center > max)
					{
						max = center;
					}
				}
				else
				{
					if(i < p)
					{
						right = center - 1;
					}
					else
					{
						left = center + 1;
					}
				}
			}
			else
			{
				right = center - 1;
			}
		}
		left = 1;
		right = max;
		min = 0;
		while(left <= right)
		{
			center = left + right;
			center /= 2;
			c = cross(n, m, i, center) * ct;
			if(c > 0)
			{
				c = cross(n-p, m, i-p, center) * cp;
				if(c > 0)
				{
					right = center - 1;
				}
				else
				{
					left = center + 1;
					if(center > min)
					{
						min = center;
					}
				}
			}
			else
			{
				left = center + 1;
				if(center > min)
				{
					min = center;
				}
			}
		}
		/*printf("%d %d\n", max, min);*/
		ans += max - min;
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
