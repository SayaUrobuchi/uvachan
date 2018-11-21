#include <stdio.h>
#include <math.h>

long long f(long long x)
{
	return (long long)(pow(log(x)+3, 3)*3+1e-10);
}

int main()
{
	int n, count;
	long long p, q, c, t;
	long long ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		p = 0;
		q = (1ll<<62);
		ans = -1;
		for(; p<=q; )
		{
			c = ((p+q) >> 1);
			t = f(c);
			if(t >= n)
			{
				q = c-1;
				if(t == n)
				{
					ans = c;
				}
			}
			else
			{
				p = c+1;
			}
		}
		if(ans == -1)
		{
			printf("BEE\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}
	return 0;
}
