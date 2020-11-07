#include <iostream>
#include <algorithm>

const int N = 1048576;

int a0[N], a1[N];

int main()
{
	int count, cas, n, i;
	long long ans;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &a0[i]);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &a1[i]);
		}
		std::sort(a0, a0+n);
		std::sort(a1, a1+n, std::greater<int>());
		for (i=0, ans=0; i<n; i++)
		{
			ans += (long long)a0[i] * a1[i];
		}
		printf("Case #%d: %lld\n", ++cas, ans);
	}
	return 0;
}
