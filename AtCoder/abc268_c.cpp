#include <iostream>
using namespace std;

const int N = 200005;

int cnt[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=n-1; j<=n+1; j++)
		{
			int pos = (t + j) % n;
			int rot = (pos - i + n) % n;
			++cnt[rot];
			ans = max(ans, cnt[rot]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
