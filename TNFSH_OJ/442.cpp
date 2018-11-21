#include<iostream>
#include <algorithm>
using namespace std;

const int N = 10000000;

int tbl[N];

int main() {
	int i, j, k, n, m, t, u, p, q, c, ba, bb, dif, res;
	for (i=3; i<3162; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=i+i; j<N; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &m);
			p = 1;
			q = 0;
			for (j=0, k=m; k>1; j++)
			{
				if (k & 1)
				{
					if (tbl[k])
					{
						t = tbl[k];
					}
					else
					{
						t = k;
					}
				}
				else
				{
					t = 2;
				}
				k /= t;
				if (!(k % t))
				{
					while (!(k % t))
					{
						k /= t;
					}
				}
				if (t > p)
				{
					q = p;
					p = t;
				}
				else if (t > q)
				{
					q = t;
				}
			}
			printf("%d %d\n", q, p);
		}
	}
	return 0;
}
