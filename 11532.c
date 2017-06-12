#include <stdio.h>

int main()
{
	int count, n, m, p, q, i, f, last;
	long long res1, res2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		p = n;
		q = m;
		res1 = 0;
		res2 = 0;
		for(i=0, last=1, f=0; n||m; i++)
		{
			if(m == 0)
			{
				n--;
				res1 += (1ll << i);
			}
			else if(n == 0)
			{
				m--;
			}
			else
			{
				if(last == 0)
				{
					last = 1;
					f = 0;
					res1 += (1ll << i);
					n--;
				}
				else if(f == 0)
				{
					f = 1;
					res1 += (1ll << i);
					n--;
				}
				else
				{
					last = 0;
					m--;
				}
			}
		}
		n = p;
		m = q;
		for(i=0, last=0, f=0; n||m; i++)
		{
			if(m == 0)
			{
				n--;
				res2 += (1ll << i);
			}
			else if(n == 0)
			{
				m--;
			}
			else
			{
				if(last == 0)
				{
					last = 1;
					f = 0;
					res2 += (1ll << i);
					n--;
				}
				else if(f == 0 && i != 1)
				{
					f = 1;
					res2 += (1ll << i);
					n--;
				}
				else
				{
					last = 0;
					m--;
				}
			}
		}
		if(res1 > res2)
		{
			printf("%lld\n", res2);
		}
		else
		{
			printf("%lld\n", res1);
		}
	}
	return 0;
}
