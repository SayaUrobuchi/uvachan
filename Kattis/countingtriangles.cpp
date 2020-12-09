#include <iostream>

double px0[64], py0[64], px1[64], py1[64];

double cross(double x, double y, double x0, double y0, double x1, double y1)
{
	return (x0-x)*(y0-y1) - (y0-y)*(x0-x1);
}

bool intersect(int p, int q)
{
	if (cross(px0[p], py0[p], px0[q], py0[q], px1[q], py1[q])
		* cross(px1[p], py1[p], px0[q], py0[q], px1[q], py1[q]) <= 0)
	{
		if (cross(px0[q], py0[q], px0[p], py0[p], px1[p], py1[p])
			* cross(px1[q], py1[q], px0[p], py0[p], px1[p], py1[p]) <= 0)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n, i, j, k, ans;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf", &px0[i], &py0[i], &px1[i], &py1[i]);
			for (j=1; j<i; j++)
			{
				if (intersect(i, j))
				{
					for (k=0; k<j; k++)
					{
						if (intersect(i, k) && intersect(k, j))
						{
							++ans;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
