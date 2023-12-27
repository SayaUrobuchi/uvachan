#include <iostream>
using namespace std;

const int N = 1005;

int dis[N], amount[N];

int main()
{
	int n, m, i, remain;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &dis[i], &amount[i]);
	}
	int ans = 0;
	for (i=0, remain=0; i<n&&dis[i]<0; i++)
	{
		int need = max(0, amount[i]-remain);
		remain -= (amount[i] - need);
		ans += (-dis[i] << 1) * ((need + m - 1) / m);
		remain += (m - need % m) % m;
	}
	for (i=n-1, remain=0; i>=0&&dis[i]>0; i--)
	{
		int need = max(0, amount[i]-remain);
		remain -= (amount[i] - need);
		ans += (dis[i] << 1) * ((need + m - 1) / m);
		remain += (m - need % m) % m;
	}
	printf("%d\n", ans);
	return 0;
}
