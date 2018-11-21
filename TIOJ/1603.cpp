#include <stdio.h>

long long dpmax[20][100005], dpmin[20][100005];

long long max(long long p, long long q)
{
	return p>q ? p : q;
}

long long min(long long p, long long q)
{
	return p<q ? p : q;
}

int main()
{
	int n, m, i, j, p, q;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%lld", &dpmax[0][i]);
		dpmin[0][i] = dpmax[0][i];
	}
	for (i=1; (1<<i)<=n; i++)
	{
		for (j=0; j+(1<<i)<=n; j++)
		{
			dpmax[i][j] = max(dpmax[i-1][j], dpmax[i-1][j+(1<<(i-1))]);
			dpmin[i][j] = min(dpmin[i-1][j], dpmin[i-1][j+(1<<(i-1))]);
		}
	}
	while (m--)
	{
		scanf("%d%d", &p, &q);
		p--;
		q--;
		for (i=1; (1<<i)<=(q-p); i++);
		i--;
		printf("%lld\n", max(dpmax[i][p], dpmax[i][q-(1<<i)+1])-min(dpmin[i][p], dpmin[i][q-(1<<i)+1]));
	}
	return 0;
}
