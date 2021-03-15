#include <iostream>
#include <cmath>

const double PI = acos(-1);
const double EPS = 1e-7;

int main()
{
	int count, cas, n, m;
	double ang, p, q, r, mid, dis, ans, a2, x;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &cas, &n, &m);
		ang = PI / n;
		// sin = r/(1+r) => (1+r)sin = r
		// => sin = r(1-sin) => r = sin/(1-sin)
		r = sin(ang) / (1-sin(ang));
		for (p=r, q=1e9; q-p>EPS; )
		{
			mid = (p+q)/2;
			// tan = mid/x => x = mid/tan
			x = mid/tan(ang);
			dis = sqrt( (x-(1+r))*(x-(1+r))+mid*mid );
			if (dis <= r+mid)
			{
				p = mid;
			}
			else
			{
				q = mid;
			}
		}
		x = (p+q)/2;
		ans = r * pow(x/r, m-1);
		a2 = ans;
		a2 *= n*2;
		a2 += 2*PI*ans;
		printf("%d %.3lf %.3lf\n", cas, ans, a2);
	}
	return 0;
}