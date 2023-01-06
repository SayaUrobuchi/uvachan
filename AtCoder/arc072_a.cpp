#include <iostream>
using namespace std;

int n;
int ary[100005];

long long calc(long long ans, int last)
{
	int i, nxt;
	for (i=1; i<n; i++)
	{
		nxt = last + ary[i];
		if (last < 0 && nxt <= 0)
		{
			ans += 1 - nxt;
			nxt = 1;
		}
		else if (last > 0 && nxt >= 0)
		{
			ans += nxt - (-1);
			nxt = -1;
		}
		last = nxt;
	}
	return ans;
}

int main()
{
	int i, u, v, a, b;
	long long ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	u = a = 0;
	v = b = ary[0];
	if (v <= 0)
	{
		u = 1 - v;
		v = 1;
	}
	if (b >= 0)
	{
		a = b - (-1);
		b = -1;
	}
	ans = min(calc(a, b), calc(u, v));
	printf("%lld\n", ans);
	return 0;
}