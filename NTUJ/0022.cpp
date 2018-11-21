#include <stdio.h>
#include <string.h>

int dp[5005][5005];
char s[5010], used[5005][5005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int recursion(int p, int q)
{
	if(used[p][q])
	{
		return dp[p][q];
	}
	used[p][q] = 1;
	if(p > q)
	{
		return dp[p][q]=0;
	}
	if(s[p] == s[q])
	{
		return dp[p][q]=recursion(p+1, q-1);
	}
	return dp[p][q]=min(recursion(p+1, q), recursion(p, q-1)) + 1;
}

int main()
{
	int count, len;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%s", &len, s);
		memset(used, 0, sizeof(used));
		printf("%d\n", recursion(0, len-1));
	}
	return 0;
}
