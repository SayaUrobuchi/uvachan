#include <iostream>
#include <cstring>

using mat = long long (*)[2];

const int M = 1e9;
const long long idd[2][2] = {{1, 0}, 
							 {0, 1}};
const long long trans[2][2] = {{0, 1}, 
							   {1, 1}};

long long buf[4][2][2];
mat res, temp, tt;

void mul(mat c, mat a, mat b)
{
	int i, j, k;
	for (i=0; i<2; i++)
	{
		for (j=0; j<2; j++)
		{
			c[i][j] = 0;
			for (k=0; k<2; k++)
			{
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % M;
			}
		}
	}
}

int main()
{
	int count, cas;
	long long n, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%lld", &cas, &n);
		res = buf[0];
		temp = buf[1];
		tt = buf[2];
		memcpy(res, idd, sizeof(idd));
		memcpy(tt, trans, sizeof(trans));
		for (t=n; t; t>>=1)
		{
			if (t & 1)
			{
				mul(temp, res, tt);
				std::swap(temp, res);
			}
			mul(temp, tt, tt);
			std::swap(temp, tt);
		}
		printf("%d %lld\n", cas, res[1][0]);
	}
	return 0;
}
