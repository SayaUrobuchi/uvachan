#include <stdio.h>
#include <string.h>

#define M 1000000007
#define N 6

long long trans[N][N] = {
	{1, 1, 0, 1, 0, 0}, 
	{1, 0, 1, 1, 0, 0}, 
	{1, 0, 0, 1, 0, 0}, 
	{0, 0, 0, 1, 1, 0}, 
	{0, 0, 0, 1, 0, 1}, 
	{0, 0, 0, 1, 0, 0}
};
long long tt[32][N][N];
long long t1[N][N], t2[N][N];
long long (*p)[N], (*q)[N], (*t)[N];

int checkRecord(int n) {
	int i, j, k, m, ans;
	memset(t1, 0, sizeof(t1));
	for (i=0; i<N; i++)
	{
		t1[i][i] = 1;
	}
	p = t1;
	q = t2;
	m = 0;
	while (n)
	{
		if (n&1)
		{
			for (i=0; i<N; i++)
			{
				for (j=0; j<N; j++)
				{
					q[i][j] = 0;
					for (k=0; k<N; k++)
					{
						q[i][j] = (q[i][j] + p[i][k]*tt[m][k][j]) % M;
					}
				}
			}
			t = p;
			p = q;
			q = t;
		}
		n >>= 1;
		++m;
	}
	ans = 0;
	for (i=0; i<N; i++)
	{
		ans = (ans+p[0][i]) % M;
	}
	return ans;
}

int main()
{
	int n, i, j, k;
	memcpy(tt[0], trans, sizeof(trans));
	for (n=1; n<32; n++)
	{
		for (i=0; i<N; i++)
		{
			for (j=0; j<N; j++)
			{
				for (k=0; k<N; k++)
				{
					tt[n][i][j] += tt[n-1][i][k] * tt[n-1][k][j];
					tt[n][i][j] %= M;
				}
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", checkRecord(n));
	}
	return 0;
}
