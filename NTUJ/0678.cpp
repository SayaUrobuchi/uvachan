#include <stdio.h>
#include <string.h>

int used[105][105][30], dp[105][105][30];
char s1[105], s2[105];

int recurs(int p, int q, int r)
{
	int i, t;
	if(p > q)
	{
		return 0;
	}
	if(used[p][q][r])
	{
		return dp[p][q][r];
	}
	used[p][q][r] = 1;
	if(s2[p] == r+'a' || (s2[p] == s1[p] && r == 26))
	{
		return dp[p][q][r]=recurs(p+1, q, r);
	}
	dp[p][q][r] = 2147483647;
	for(i=p; i<=q; i++)
	{
		if(s2[i] == s2[p] && s2[i] != s2[i+1])
		{
			t = recurs(p+1, i, s2[p]-'a') + recurs(i+1, q, r) + 1;
			if(t < dp[p][q][r])
			{
				dp[p][q][r] = t;
			}
		}
	}
	return dp[p][q][r];
}

int main()
{
	while(scanf("%s%s", s1, s2) == 2)
	{
		memset(used, 0, sizeof(used));
		printf("%d\n", recurs(0, strlen(s1)-1, 26));
	}
	return 0;
}
