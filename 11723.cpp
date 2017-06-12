#include <stdio.h>

int main()
{
	int n, m, res, cas;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		res = (n-1)/m;
		if(res > 26)
		{
			printf("Case %d: impossible\n", ++cas);
		}
		else
		{
			printf("Case %d: %d\n", ++cas, res);
		}
	}
	return 0;
}
