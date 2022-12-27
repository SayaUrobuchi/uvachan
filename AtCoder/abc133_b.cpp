#include <iostream>
#include <cmath>
using namespace std;

int ary[16][16];

bool judge(int t)
{
	int k = sqrt(t) + 1e-7;
	return k*k == t;
}

int main()
{
	int n, m, i, j, k, t, ans;
	scanf("%d%d", &n, &m);
	for (i=0, ans=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &ary[i][j]);
		}
		for (j=0; j<i; j++)
		{
			for (k=0, t=0; k<m; k++)
			{
				t += (ary[i][k]-ary[j][k]) * (ary[i][k]-ary[j][k]);
			}
			ans += judge(t);
		}
	}
	printf("%d\n", ans);
	return 0;
}