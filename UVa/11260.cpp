#include <stdio.h>
#include <math.h>

const double EPS = 1e-7;
const int M = 100000000;

int main()
{
	long long n, m, t, p, q, ans;
	while (scanf("%lld", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		if (!(n & 1))
		{
			--n;
		}
		m = (long long)(sqrt(n) + EPS);
		t = ((m + (m&1) - 1) >> 1);
		// (1+2)*2 + (3+4)*4 + (5+6)*6 + ...
		// 2 x (3*1 + 7*2 + 11*3 + ...)
		// 2 x ( (4-1)*1 + (8-1)*2 + (12-1)*3 + ...)
		// 8 x (1*1 + 2*2 + 3*3 + ...) - 4 x (1 + 2 + 3 + ...)
		// 8 x ( n * (n+1) * (n+n+1) / 6 ) - 2 x ( n * (n+1) / 2 )
		p = t * (t+1) / 2;
		if (p % 3 == 0)
		{
			p = (((p / 3) % M) * (t+t+1)) % M;
		}
		else
		{
			p = ((p % M) * ((t+t+1) / 3)) % M;
		}
		p = (p << 3) % M;
		q = (t * (t+1) / 2) % M;
		q = (q << 1) % M;
		q = M - q;
		ans = (p + q) % M;
		for (t=(t<<1)+1; t<=m; t++)
		{
			p = (t+1) * (t+1);
			if (p > n)
			{
				p = n;
			}
			ans = (ans + (((p - t*t) >> 1) + 1) * t) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
