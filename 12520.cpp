#include <stdio.h>

int main()
{
	long long n, m, t, tt, ans;
	while(scanf("%lld%lld", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		t = n*n;
		if(m <= ((t+1)>>1))
		{
			printf("%lld\n", m<<2);
			continue;
		}
		ans = ((t+1)>>1<<2);
		if(!(n&1) && m <= ((t+1)>>1)+2)
		{
			printf("%lld\n", ans);
			continue;
		}
		tt = (n<<2)-4+(((n-2)*(n-2)-(n&1)*2)>>1);
		if(m <= tt)
		{
			m -= ((t+1)>>1);
			if(!(n&1))
			{
				m -= 2;
			}
			else if(m >= 3)
			{
				m--;
			}
			printf("%lld\n", ans-(m<<1));
			continue;
		}
		ans -= ((tt-1-((t+1)>>1)+1)<<1);
		/*printf("!! %lld\n", ans);*/
		m -= tt;
		ans -= ((m-1)<<2);
		printf("%lld\n", ans);
	}
	return 0;
}
