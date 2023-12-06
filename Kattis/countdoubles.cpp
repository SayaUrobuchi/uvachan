#include <iostream>
using namespace std;

const int N = 1024;

int pre[N];

int main()
{
	int n, m, i, t, ans;
	scanf("%d%d", &n, &m);
	for (i=1, ans=0; i<=n; i++)
	{
		scanf("%d", &t);
		pre[i] = pre[i-1] + !(t & 1);
		if (i >= m && pre[i] - pre[i-m] >= 2)
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
