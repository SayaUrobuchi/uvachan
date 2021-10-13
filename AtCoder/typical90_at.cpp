#include <iostream>
#include <cstring>
using namespace std;

const int M = 46;

int ary[4][64];

int main()
{
	int n, i, j, t;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		memset(ary, 0, sizeof(ary));
		for (i=0; i<3; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &t);
				++ary[i][t%M];
			}
		}
		for (i=0, ans=0; i<M; i++)
		{
			if (ary[0][i])
			{
				for (j=0; j<M; j++)
				{
					ans += (long long)ary[0][i] * ary[1][j] * ary[2][(M-(i+j)%M)%M];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
