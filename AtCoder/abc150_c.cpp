#include <iostream>
using namespace std;

const int N = 12;

int p[N];
int fac[N];

int main()
{
	int n, i, j, k;
	fac[0] = 1;
	for (i=1; i<=N; i++)
	{
		fac[i] = fac[i-1] * i;
	}
	scanf("%d", &n);
	int p[2] = {};
	for (i=0; i<2; i++)
	{
		bool appr[N] = {};
		for (j=0; j<n; j++)
		{
			int t;
			scanf("%d", &t);
			appr[t] = true;
			for (k=1; k<t; k++)
			{
				if (!appr[k])
				{
					p[i] += fac[n-j-1];
				}
			}
		}
	}
	printf("%d\n", abs(p[0]-p[1]));
	return 0;
}
