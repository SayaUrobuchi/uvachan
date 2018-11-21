#include <stdio.h>

int main()
{
	int n, m, i, j;
	long long res;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1, res=0; i<n&&i<m; i++)
		{
			res += i*(long long)(n-i)*(m-i);
		}
		printf("%lld\n", res);
	}
	return 0;
}
