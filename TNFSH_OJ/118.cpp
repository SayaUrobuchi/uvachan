#include <stdio.h>

int ary[1024];

int main()
{
	int n, m, i, p, q;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d%d", &p, &q);
		ary[p] = p*q;
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &p, &q);
		q -= ary[p];
		printf(q?"%d\n":"The shopkeeper is honest.\n", q);
	}
	return 0;
}
