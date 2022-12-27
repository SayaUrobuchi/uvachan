#include <iostream>
using namespace std;

int ary[4][131072], tbl[131072];

int main()
{
	int n, i, j;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (j=0; j<3; j++)
		{
			for (i=0; i<n; i++)
			{
				scanf("%d", &ary[j][i]);
			}
		}
		for (i=1; i<=n; i++)
		{
			tbl[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			++tbl[ary[1][ ary[2][i]-1 ]];
		}
		for (i=0, ans=0; i<n; i++)
		{
			ans += tbl[ary[0][i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

