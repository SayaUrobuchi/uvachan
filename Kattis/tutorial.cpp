#include <iostream>
#include <cmath>

int main()
{
	long long n, res;
	int m, t, i;
	while (scanf("%lld%d%d", &n, &m, &t) == 3)
	{
		if (t == 1)
		{
			for (i=2, res=1; i<=m&&res<=n; res*=i, i++);
		}
		else if (t == 2)
		{
			for (i=0, res=1; i<m&&res<=n; res*=2, i++);
		}
		else if (t == 3)
		{
			for (i=0, res=1; i<4&&res<=n; res*=m, i++);
		}
		else if (t == 4)
		{
			for (i=0, res=1; i<3&&res<=n; res*=m, i++);
		}
		else if (t == 5)
		{
			res = (long long)m*m;
		}
		else if (t == 6)
		{
			res = ceil(m*log2(m));
		}
		else
		{
			res = m;
		}
		//printf("%lld %lld\n", res, n);
		puts(res<=n?"AC":"TLE");
	}
	return 0;
}
