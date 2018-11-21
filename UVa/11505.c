#include <stdio.h>
#include <math.h>

int main()
{
	int count, n, i, val;
	double x, y, pi, ang;
	char cmd[20];
	pi = 2.0 * acos(0.0);
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, x=0.0, y=0.0, ang=0.0; i<n; i++)
		{
			scanf("%s%d", cmd, &val);
			if(*cmd == 'f')
			{
				x += val * cos(ang);
				y += val * sin(ang);
			}
			else if(*cmd == 'b')
			{
				x -= val * cos(ang);
				y -= val * sin(ang);
			}
			else if(*cmd == 'l')
			{
				ang += val / 180.0 * pi;
			}
			else if(*cmd == 'r')
			{
				ang -= val / 180.0 * pi;
			}
		}
		printf("%.0lf\n", sqrt(x*x+y*y));
	}
	return 0;
}

