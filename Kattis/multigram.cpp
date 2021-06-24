#include <iostream>
#include <algorithm>

int ary[131072];
int pre[131072][128];
char s[131072];

int main()
{
	int n, m, i, j, k, t, u, ans;
	bool gg;
	while (scanf("%s", s+1) == 1)
	{
		for (i=1; s[i]; i++)
		{
			for (j='a'; j<='z'; j++)
			{
				pre[i][j] = pre[i-1][j];
				if (j == s[i])
				{
					++pre[i][j];
				}
			}
		}
		n = i-1;
		ans = -1;
		m = 1;
		ary[0] = 1;
		for (i=2; i*i<=n; i++)
		{
			ary[m] = i;
			++m;
			if (i*i != n)
			{
				ary[m] = n/i;
				++m;
			}
		}
		std::sort(ary, ary+m);
		for (u=0; u<m; u++)
		{
			i = ary[u];
			t = n/i;
			for (k='a', gg=false; k<='z'; k++)
			{
				if (pre[i][k]*t != pre[n][k])
				{
					gg = true;
					break;
				}
			}
			if (!gg)
			{
				for (j=i+i; j<=n&&!gg; j+=i)
				{
					for (k='a'; k<='z'; k++)
					{
						if (pre[i][k] != pre[j][k] - pre[j-i][k])
						{
							gg = true;
							break;
						}
					}
				}
				if (!gg)
				{
					ans = i;
					break;
				}
			}
		}
		if (ans < 1)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("%.*s\n", ans, s+1);
		}
	}
	return 0;
}
