#include <iostream>
using namespace std;

int px[1024], py[1024];

int main()
{
	int n, i, a, b;
	double area;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0, area=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			if (i)
			{
				area += px[i-1]*py[i] - px[i]*py[i-1];
			}
		}
		area += px[n-1]*py[0] - px[0]*py[n-1];
		a = 1, b = 0;
		if (area < 0)
		{
			swap(a, b);
			area = -area;
		}
		area /= 2;
		if (a > b)
		{
			printf("CCW %.1lf\n", area);
		}
		else
		{
			printf("CW %.1lf\n", area);
		}
	}
	return 0;
}
