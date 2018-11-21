#include <stdio.h>

int conn(long long int p, long long int q)
{
	int res;
	if(p > q)
	{
		return conn(q, p);
	}
	res = 0;
	while(q > p)
	{
		q >>= 1;
		res++;
	}
	if(p == q)
	{
		return res;
	}
	return -1;
}

int get_dis(long long int p, long long int q)
{
	int res;
	res = 0;
	while(p != q)
	{
		if(p > q)
		{
			p >>= 1;
		}
		else
		{
			q >>= 1;
		}
		res++;
	}
	return res;
}

int main()
{
	int count, n, ax, ay, bx, by, m, i, j, d, ans;
	long long s, p, q, r;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d%d", &n, &ax, &ay, &bx, &by, &m);
		s = 1;
		for(i=1; i<n; i++)
		{
			s <<= 1;
		}
		s--;
		//for(i=0, p=ax+s; i<n&&i<=ay&&i<ay-i; i++, p>>=1);
		//for(i=0, q=bx+s; i<n&&i<=by&&i<by-i; i++, q>>=1);
		p = ax+s;
		q = bx+s;
		while(p != q)
		{
			if(p > q)
			{
				p >>= 1;
			}
			else
			{
				q >>= 1;
			}
		}
		r = p;
		for(i=0, p=ax+s, ans=0; i<n&&i<=ay; i++, p>>=1)
		{
			if(i >= ay-i)
			{
				for(j=0, q=bx+s; j<n&&j<=by; j++, q>>=1)
				{
					if(j >= by-j)
					{
						d = conn(p, q);
						if(d != -1)
						{
							if(d == 0 && p == 1 && p < r)
							{
								if(by-j && ay-i)
								{
									d = -2;
								}
							}
							if(d+by-j+ay-i > ans)
							{
								ans = d+by-j+ay-i;
							}
						}
						else
						{
							d = get_dis(p, q);
							if(d+by-j+ay-i > ans)
							{
								ans = d+by-j+ay-i;
							}
						}
					}
				}
			}
		}
		printf(ans>m?"YES\n":"NO\n");
	}
	return 0;
}
