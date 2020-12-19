#include <iostream>
#include <algorithm>

using ppp = std::pair<int, int>;

ppp pp[1048576], res[1048576];

long long cross(ppp a, ppp b, ppp c)
{
	return (a.first-b.first)*(b.second-c.second)-(b.first-c.first)*(a.second-b.second);
}

int main()
{
	int n, i, j, k;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &pp[i].first, &pp[i].second);
		}
		std::sort(pp, pp+n);
		for (i=0, j=-1, k=0; i<n; i++)
		{
			for (; j>k&&cross(res[j-1], res[j], pp[i])<=0; j--);
			res[++j] = pp[i];
		}
		k = j;
		for (i=n-2; i>=0; i--)
		{
			for (; j>k&&cross(res[j-1], res[j], pp[i])<=0; j--);
			res[++j] = pp[i];
		}
		for (i=1, ans=0; i<=j; i++)
		{
			ans += res[i].first*res[i-1].second - res[i-1].first*res[i].second;
			//printf("(%d, %d)\n", res[i].first, res[i].second);
		}
		printf("%.1lf\n", std::abs(ans)*0.5);
	}
	return 0;
}
