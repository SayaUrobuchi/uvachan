#include <iostream>
#include <algorithm>
using namespace std;

long long ary[100005];

int main()
{
	int m, i;
	unsigned long long n, last, mid, ans;
	unsigned long long p, q;
	bool gg;
	while (scanf("%llu%d", &n, &m) == 2)
	{
		//printf("%llu\n", n);
		for (i=0; i<m; i++)
		{
			scanf("%llu", &ary[i]);
		}
		sort(ary, ary+m);
		for (p=1, q=n, ans=0; p<=q; )
		{
			mid = p+((q-p)>>1);
			for (i=0, last=0, gg=false; i<m; i++)
			{
				if (ary[i] > last+mid)
				{
					gg = true;
					break;
				}
				last = min(last+mid, ary[i]+mid-1);
			}
			//printf(".. %lld %lld %lld %d\n", mid, p, q, gg);
			if (last < n)
			{
				gg = true;
			}
			if (gg)
			{
				p = mid+1;
			}
			else
			{
				q = mid-1;
				ans = mid;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

