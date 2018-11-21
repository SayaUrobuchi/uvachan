#include <stdio.h>

int ary[100005];

int gcd(int p, int q)
{
	return p%q ? gcd(q, p%q) : q;
}

int main()
{
	int n, m, i, j, sum, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, sum=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &temp);
			}
			sum += temp;
			ary[i] = temp;
		}
		for(i=0; i<n; i++)
		{
			printf("%d / %d\n", ary[i]/gcd(ary[i], sum), sum/gcd(ary[i], sum));
		}
	}
	return 0;
}
