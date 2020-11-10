#include <iostream>
#include <cstring>

int ary[1024];

int main()
{
	int count, n, m, i, j, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		memset(ary, 0, sizeof(ary));
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%1d", &t);
				ary[j] += t;
			}
		}
		for (j=0; j<m; j++)
		{
			putchar((ary[j]<<1) < n ? '0' : '1');
		}
		puts("");
	}
	return 0;
}
