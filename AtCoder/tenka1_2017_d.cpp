#include <iostream>
using namespace std;

const int N = 100005;

int ary[N], bry[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i], &bry[i]);
	}
	long long ans = 0;
	for (i=30; i>=0; i--)
	{
		int flag = (1 << i);
		if (m & flag)
		{
			long long t = 0;
			for (j=0; j<n; j++)
			{
				if (ary[j] < flag)
				{
					t += bry[j];
				}
				ary[j] &= ~flag;
			}
			ans = max(ans, t);
		}
	}
	long long u = 0;
	for (i=0; i<n; i++)
	{
		if (ary[i] == 0)
		{
			u += bry[i];
		}
	}
	ans = max(ans, u);
	printf("%lld\n", ans);
	return 0;
}