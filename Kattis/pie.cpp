#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);
const int N = 10005;

int ary[N];

int main()
{
	int count, n, m, i, j, best;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0, best=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			best = max(best, ary[i]);
		}
		double l, r;
		for (i=0, l=0, r=best*best*PI; i<100; i++)
		{
			double mid = (l+r) / 2;
			int cnt = 0;
			for (j=0; j<n; j++)
			{
				cnt += floor(ary[j]*ary[j]*PI/mid);
			}
			if (cnt >= m+1)
			{
				l = mid;
			}
			else
			{
				r = mid;
			}
		}
		printf("%.10lf\n", l);
	}
	return 0;
}
