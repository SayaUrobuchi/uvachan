#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		ans += ary[t];
	}
	printf("%d\n", ans);
	return 0;
}
