#include <stdio.h>

int used[100005], ary[100005];

int main()
{
	int cnt, n, i, j, ans;
	cnt = 0;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		++cnt;
		ans = 0;
		for (i=0; i<n; i++)
		{
			if (used[i] != cnt)
			{
				used[i] = cnt;
				for (j=ary[i]; used[j]!=cnt; j=ary[j])
				{
					used[j] = cnt;
				}
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
