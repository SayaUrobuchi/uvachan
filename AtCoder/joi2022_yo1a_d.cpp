#include <iostream>
using namespace std;

const int N = 128;
const int M = 2048;

int ary[N];
int cnt[M];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		++cnt[ary[i]];
	}
	int ans = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		ans += cnt[t];
		cnt[t] = 0;
	}
	printf("%d\n", ans);
	return 0;
}
