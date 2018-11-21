#include <stdio.h>
#include <math.h>

int main()
{
	int cas, count, n, i, sq, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &cas, &n);
		for(i=2, sq=sqrt(n)+1, ans=n%2; i<sq; i++)
		{
			if(n % i == 0)
			{
				ans += (i%2) + (n/i%2);
			}
		}
		if((sq-1)*(sq-1) == n)
		{
			ans -= (sq-1)%2;
		}
		printf("%d %d\n", cas, ans);
	}
	return 0;
}
