#include <iostream>
#include <vector>
using namespace std;

int cnt[1048576];

int main()
{
	int n, m, i, t, u, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			cnt[i] = 0;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &t, &u);
			if (t < u)
			{
				++cnt[u];
			}
			else
			{
				++cnt[t];
			}
		}
		for (i=1, ans=0; i<=n; i++)
		{
			if (cnt[i] == 1)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
