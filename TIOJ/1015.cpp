#include <stdio.h>

int main()
{
	long long n, m, temp, ans;
	while(scanf("%I64d%I64d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		if(n > m)
		{
			temp = n;
			n = m;
			m = temp;
		}
		ans = (m-n)*((1+n)*n/2) + n*(n+1)*(n+n+1)/6;
		printf("%I64d\n", ans);
	}
	return 0;
}
