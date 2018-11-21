#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int n, cas, nsqrt, i, j, ans, tmp, tmp2, check;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		if(n == 1)
		{
			printf("Case %d: 2\n", ++cas);
			continue;
		}
		check = 0;
		tmp2 = n;
		nsqrt = sqrt(n) + 1;
		ans = 0;
		if(!(n % 2))
		{
			check = 1;
			tmp = 1;
			while(!(n % 2))
			{
				n /= 2;
				tmp *= 2;
			}
			ans += tmp;
		}
		for(i=3; n > 1 && i < nsqrt; i+=2)
		{
			if(!(n % i))
			{
				check++;
				tmp = 1;
				while(!(n % i))
				{
					n /= i;
					tmp *= i;
				}
				ans += tmp;
			}
		}
		if(n > 1)
		{
			check++;
			ans += n;
		}
		if(check == 1)
		{
			ans++;
		}
		printf("Case %d: %lu\n", ++cas, ans);
	}
	return 0;
}
