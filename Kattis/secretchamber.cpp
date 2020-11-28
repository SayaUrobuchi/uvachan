#include <iostream>
#include <cstring>

int dp[32][32];
char p[1024], q[1024];

int main()
{
	int n, m, i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		for (i=0; i<26; i++)
		{
			dp[i][i] = true;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s%s", p, q);
			dp[*p-'a'][*q-'a'] = true;
		}
		for (k=0; k<26; k++)
		{
			for (i=0; i<26; i++)
			{
				for (j=0; j<26; j++)
				{
					if (dp[i][k] && dp[k][j])
					{
						dp[i][j] = true;
					}
				}
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%s%s", p, q);
			if (strlen(p) != strlen(q))
			{
				puts("no");
				continue;
			}
			for (j=0; p[j]; j++)
			{
				if (!dp[p[j]-'a'][q[j]-'a'])
				{
					break;
				}
			}
			puts(p[j] ? "no" : "yes");
		}
	}
	return 0;
}
