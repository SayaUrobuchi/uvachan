#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const int N = 32;

double px[N], py[N];

double rad(double t)
{
	return t/180*PI;
}

double dis(double a, double b, double c, double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
	int n, i;
	double a, b, x, y, t, dir, best;
	string s, cmd;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		getline(cin, s);
		for (i=0, a=0, b=0; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> x >> y;
			while (ss >> cmd >> t)
			{
				if (cmd == "start")
				{
					dir = rad(t);
				}
				else if (cmd == "walk")
				{
					x += t * cos(dir);
					y += t * sin(dir);
				}
				else
				{
					dir += rad(t);
				}
			}
			px[i] = x;
			py[i] = y;
			//printf("pos %.6lf %.6lf\n", x, y);
			a += x;
			b += y;
		}
		a /= n;
		b /= n;
		best = dis(a, b, px[0], py[0]);
		for (i=1; i<n; i++)
		{
			best = std::max(best, dis(a, b, px[i], py[i]));
		}
		printf("%.10lf %.10lf %.10lf\n", a, b, best);
	}
	return 0;
}
