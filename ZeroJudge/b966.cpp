#include <stdio.h>
#include <algorithm>

#define N 10005

int st[N], ed[N], idx[N];

bool cmp(int a, int b)
{
	return st[a] < st[b];
}

int main()
{
	int n, i, k, ss, last, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &st[i], &ed[i]);
			idx[i] = i;
		}
		std::sort(idx, idx+n, cmp);
		ss = last = -1048576;
		ans = 0;
		for (i=0; i<n; i++)
		{
			k = idx[i];
			if (last < st[k])
			{
				ans += last-ss;
				ss = st[k];
				last = ed[k];
			}
			else if (ed[k] > last)
			{
				last = ed[k];
			}
		}
		ans += last-ss;
		printf("%d\n", ans);
	}
	return 0;
}
