#include <stdio.h>
#include <math.h>

int main()
{
	int n, m, i, p, q;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		m = n;
		n += n;
		for(i=sqrt(n); i; i--)
		{
			if(!(n % i))
			{
				if((i%2) ^ ((n/i)%2))
				{
					n /= i;
					q = i+n;
					p = n-i;
					printf("%d = %d + ... + %d\n", m, p/2+1, q/2);
					break;
				}
			}
		}
	}
	return 0;
}
