#include <iostream>
using namespace std;

const int N = 10005;

int cnt[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		++cnt[t];
	}
	int ans = 0;
	for (i=0; i<N; i++)
	{
		ans += (cnt[i]+i) / (i+1) * (i+1);
	}
	printf("%d\n", ans);
	return 0;
}
