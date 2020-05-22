#include <stdio.h>

int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (m < n+n)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (i=1; i<n; i++)
		{
			printf("1 ");
		}
		printf("%d\n%d\n", m-(n-1), n);
	}
	return 0;
}
