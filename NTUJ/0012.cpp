#include <stdio.h>

char s[10000];

int main()
{
	int count;
	long long i, j, k, a, b, c, d, e, f, p, q, tail, ans, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lld", &tail);
		for(i=1, j=10, ans=0; i<=tail; i*=10, j*=10)
		{
			for(temp=tail%j; ans+i<j; ans+=i)
			{
				/*printf("%lld: %lld %lld\n", ans, (((ans * ans) % j) * ans) % j, temp);*/
				if(i == 1000000000)
				{
					p = ans / i;
					q = ans % i;
					a = p * p;
					b = p * q + q * p;
					c = q * q;
					b += c / i;
					c %= i;
					a += b / i;
					b %= i;
					sprintf(s, "%lld%09lld%09lld\0", a, b, c);
					for(k=0, c=0; s[k]; k++)
					{
						c *= 10;
						c += s[k] - '0';
						c %= j;
					}
					b = c / i;
					c %= i;
					d = p * b;
					e = p * c + q * b;
					f = q * c;
					e += f / i;
					f %= i;
					d += e / i;
					e %= i;
					sprintf(s, "%lld%09lld%09lld\0", d, e, f);
					for(k=0, f=0; s[k]; k++)
					{
						f *= 10;
						f += s[k] - '0';
						f %= j;
					}
					if(f == temp)
					{
						break;
					}
				}
				else
				{
					if((((ans * ans) % j) * ans) % j == temp)
					{
						break;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
