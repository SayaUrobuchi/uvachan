#include <iostream>
using namespace std;

int cnt[100005];

int main()
{
	int n, i, a, b;
	bool ans;
	scanf("%d", &n);
	for (i=1; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		++cnt[a];
		++cnt[b];
	}
	ans = false;
	for (i=1; i<=n; i++)
	{
		if (cnt[i] == n-1)
		{
			ans = true;
		}
	}
	printf("%s\n", ans?"Yes":"No");
	return 0;
}
