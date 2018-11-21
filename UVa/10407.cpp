#include <stdio.h>

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int temp, now, ans;
	while(scanf("%d", &temp) == 1)
	{
		if(!temp)
		{
			break;
		}
		ans = 0;
		while(scanf("%d", &now) == 1)
		{
			if(!now)
			{
				break;
			}
			if(ans)
			{
				if(now -= temp)
				{
					ans = gcd(ans, ab(now));
				}
			}
			else
			{
				ans = ab(now - temp);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
