#include <stdio.h>
#include <math.h>

int ary[16][16], px[16], py[16];

double getdis(int x, int y)
{
	return sqrt(x*x+y*y);
}

int main()
{
	int i, j, t, x, y;
	double ans;
	while (scanf("%d%d%d", &ary[0][0], &ary[0][1], &ary[0][2]) == 3)
	{
		for (i=1; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				t = ary[i][j];
				px[t] = i;
				py[t] = j;
			}
		}
		for (i=2, ans=0, x=px[1], y=py[1]; i<=9; i++)
		{
			ans += getdis(x-px[i], y-py[i]);
			x = px[i];
			y = py[i];
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
