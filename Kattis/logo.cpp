#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

char cmd[8];

double to_rad(double deg)
{
	return deg * PI / 180.0;
}

double get_dis(double dx, double dy)
{
	return sqrt(dx*dx + dy*dy);
}

int main()
{
	int count, n, i, d;
	double x, y, ang;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, x=0, y=0, ang=0; i<n; i++)
		{
			scanf("%s%d", cmd, &d);
			if (*cmd == 'l')
			{
				ang += to_rad(d);
			}
			else if (*cmd == 'r')
			{
				ang -= to_rad(d);
			}
			else
			{
				int sig = 1;
				if (*cmd == 'b')
				{
					sig = -1;
				}
				x += sig * d * cos(ang);
				y += sig * d * sin(ang);
			}
		}
		printf("%.0lf\n", get_dis(x, y));
	}
	return 0;
}
