#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
	int count, n, i, t;
	double cnt;
	double r, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lf%d", &r, &n);
		for (i=0, ans=0, cnt=1, t=4; i<n; i++, cnt*=t, t=3, r/=2)
		{
			ans += PI*r*r*cnt;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
