#include <stdio.h>
#include <math.h>

const double PI=2.0*acos(0.0);

int getdis(int x, int y)
{
	return x*x+y*y;
}

double getang(int x1, int y1, int x2, int y2)
{
	int a, b, c;
	a = getdis(x1, y1);
	b = getdis(x2, y2);
	c = getdis(x1-x2, y1-y2);
	return acos((a*a+b*b-c*c)/(2.0*a*b)) / PI * 180.0;
}

int main()
{
	int count, i, h, r, x1, x2, x3, y1, y2, y3;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d%d%d", &r, &x1, &y1, &x2, &y2, &x3, &y3);
		h = 0;
		r *= r;
		if(getdis(x1, y1) < r && getdis(x2, y2) < r && getdis(x3, y3) < r)
		{
			if(getang(x1, y1, x2, y2) >= 120.0 || getang(x1, y1, x3, y3) >= 120.0 || getang(x2, y2, x3, y3) >= 120.0)
			{
				h = 1;
			}
		}
		if(h)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
