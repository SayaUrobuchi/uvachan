#include <stdio.h>

const int N = 100005;

char s[N];
int jmp[N], dp[N], res[N];

int main()
{
	int n, i, j, ans;
	while (scanf("%s", s) == 1)
	{
		jmp[0] = -1;
		dp[0] = 1;
		for (i=1, j=0; s[i]; i++, j++)
		{
			jmp[i] = j;
			dp[i] = 1;
			while (j >= 0 && s[i] != s[j])
			{
				j = jmp[j];
			}
		}
		jmp[i] = j;
		n = i;
		dp[n] = 1;
		ans = 0;
		for (i=n, j=i; i>0&&j>=0; i--)
		{
			if (i == j)
			{
				res[ans] = i;
				ans++;
				j = jmp[j];
			}
			dp[jmp[i]] += dp[i];
		}
		printf("%d\n", ans);
		for (--ans; ans>=0; ans--)
		{
			printf("%d %d\n", res[ans], dp[res[ans]]);
		}
	}
	return 0;
}
