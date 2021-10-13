#include <iostream>
using namespace std;
using mat = int (*)[64];

const int M = 1000000007;

int buf[4][64][64];

void mul(mat c, mat a, mat b, int n)
{
	int i, j, k;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			c[i][j] = 0;
			for (k=0; k<n; k++)
			{
				c[i][j] = (c[i][j] + (a[i][k] * (long long)b[k][j])) % M;
			}
		}
	}
}

int main()
{
	int n, i, j, sum;
	long long m;
	mat tt, ans, tmp;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		tt = buf[0];
		ans = buf[1];
		tmp = buf[2];
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &tt[i][j]);
				ans[i][j] = (i==j);
			}
		}
		for (; m; m>>=1)
		{
			if (m & 1)
			{
				mul(tmp, ans, tt, n);
				swap(tmp, ans);
			}
			mul(tmp, tt, tt, n);
			swap(tmp, tt);
		}
		for (i=0, sum=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				sum = (sum + ans[i][j]) % M;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
