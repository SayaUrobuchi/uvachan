#include <stdio.h>

int ary[10005];

int gcd(int p, int q)
{
	return p%q ? gcd(q, p%q) : q;
}

int main()
{
	int n, m, i, j, sum, g;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0, sum=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &ary[i]);
			}
			sum += ary[i];
		}
		for(i=0; i<n; i++)
		{
			g = gcd(ary[i], sum);
			printf("%d / %d\n", ary[i]/g, sum/g);
		}
	}
	return 0;
}
