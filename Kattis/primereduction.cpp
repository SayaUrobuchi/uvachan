#include <iostream>
using namespace std;

const int RNG = 40000;

int pc;
int pri[RNG], tbl[RNG];

void sieve()
{
	int i, j;
	for (i=2, pc=0; i<RNG; i++)
	{
		if (!tbl[i])
		{
			pri[pc++] = i;
		}
		for (j=0; i*pri[j]<RNG; j++)
		{
			tbl[i*pri[j]] = pri[j];
			if (i % pri[j] == 0)
			{
				break;
			}
		}
	}
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n) == 1)
	{
		if (n == 4)
		{
			break;
		}
		int a, b, i;
		for (b=1; ; b++)
		{
			if (n < RNG)
			{
				for (a=0; tbl[n]; a+=tbl[n], n/=tbl[n]);
			}
			else
			{
				for (i=0, a=0; pri[i]*pri[i]<=n; i++)
				{
					if (n % pri[i] == 0)
					{
						while (n % pri[i] == 0)
						{
							n /= pri[i];
							a += pri[i];
						}
					}
				}
			}
			if (a == 0)
			{
				a = n;
				break;
			}
			if (n > 1)
			{
				a += n;
			}
			n = a;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}
