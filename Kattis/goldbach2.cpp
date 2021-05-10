#include <iostream>

int pn;
int p[32768], tbl[32768], ary[32768];

int main()
{
	int count, n, m, i, j, k;
	p[0] = 2;
	pn = 1;
	for (i=3; i<32768; i+=2)
	{
		if (!tbl[i])
		{
			p[pn++] = i;
			for (j=i*i, k=i+i; j<32768; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, m=0; p[i]+p[i]<=n; i++)
		{
			j = n - p[i];
			if (((j & 1) && !tbl[n-p[i]]) || j == 2)
			{
				ary[m++] = p[i];
			}
		}
		printf("%d has %d representation(s)\n", n, m);
		for (i=0; i<m; i++)
		{
			printf("%d+%d\n", ary[i], n-ary[i]);
		}
		puts("");
	}
	return 0;
}
