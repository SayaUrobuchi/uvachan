#include <iostream>
#include <cstring>

int ary[1024];

int main()
{
	int n, m, o, i, t, ans;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		memset(ary, 0, sizeof(ary));
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			--ary[t];
		}
		for (i=0; i<o; i++)
		{
			scanf("%d", &t);
			++ary[t];
		}
		for (i=1, ans=0; i<=n; i++)
		{
			if (ary[i] < 0)
			{
				if (ary[i-1] > 0)
				{
					--ary[i-1];
				}
				else if (ary[i+1] > 0)
				{
					--ary[i+1];
				}
				else
				{
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
