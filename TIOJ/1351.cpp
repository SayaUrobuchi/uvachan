#include <stdio.h>
#include <math.h>

int main()
{
	int count, n, i, h, m, s, sq;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		for(i=2+n%2, h=2, m=n+1, s=1+n%2, sq=sqrt(n)+1; i<sq; i+=s)
		{
			if(n % i == 0)
			{
				if(i*i == n)
				{
					h++;
					m += i;
				}
				else
				{
					h += 2;
					m += i + n / i;
				}
			}
		}
		printf("%I64d\n", (long long)h*m);
	}
	return 0;
}
