#include <iostream>

int ary[2048];
char s[2048];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<m; i++)
		{
			ary[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0; j<m; j++)
			{
				if (s[j] == '$')
				{
					ary[j] |= 1;
				}
			}
		}
		for (i=0, ans=1; i<m; i++)
		{
			if (!ary[i])
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
