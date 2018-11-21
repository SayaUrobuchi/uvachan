#include <stdio.h>

int main()
{
	int count, cas, n, i, m, j;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		m = j = 0;
		while (n--)
		{
			scanf("%d", &i);
			m += (i/30+1) * 10;
			j += (i/60+1) * 15;
		}
		printf("Case %d:", ++cas);
		if (m <= j)
		{
			printf(" Mile");
		}
		if (j <= m)
		{
			printf(" Juice");
		}
		printf(" %d\n", m<j?m:j);
	}
	return 0;
}
