#include <iostream>
#include <algorithm>

int n;
long long ary[1048576];

long long calc(long long t)
{
	int i, p, q, r, mid;
	long long res;
	for (i=0, res=0; i<n; i++)
	{
		if (ary[i] == 0)
		{
			if (t > 0)
			{
				res += n-1;
			}
		}
		else if (ary[i] > 0)
		{
			for (p=0, q=n-1, r=-1; p<=q; )
			{
				mid = ((p+q)>>1);
				if (ary[i] * ary[mid] < t)
				{
					r = mid;
					p = mid+1;
				}
				else
				{
					q = mid-1;
				}
			}
			if (r >= i)
			{
				--r;
			}
			res += r+1;
		}
		else
		{
			for (p=0, q=n-1, r=n; p<=q; )
			{
				mid = ((p+q)>>1);
				if (ary[i] * ary[mid] < t)
				{
					r = mid;
					q = mid-1;
				}
				else
				{
					p = mid+1;
				}
			}
			if (r <= i)
			{
				++r;
			}
			res += n-r;
		}
	}
	return res;
}

int main()
{
	int i;
	long long m, p, q, r, mid, res;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		m <<= 1;
		for (i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (p=-1e18, q=1e18, r=p; p<=q; )
		{
			mid = ((p+q)>>1);
			res = calc(mid);
			if (res < m)
			{
				r = mid;
				p = mid+1;
			}
			else
			{
				q = mid-1;
			}
		}
		printf("%lld\n", r);
	}
	return 0;
}
