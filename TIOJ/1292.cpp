#include <stdio.h>
#include <string.h>

#define WHITE 0
#define BLACK 1

int num[10005], map[10005][105], dp[10005][2];

int min(int p, int q)
{
	return p < q ? p : q;
}

void recursion(int now, int parent)
{
	int i, wtemp, btemp, temp;
	for(i=0, wtemp=0, btemp=0; i<num[now]; i++)
	{
		if((temp=map[now][i]) != parent)
		{
			recursion(temp, now);
			btemp += min(dp[temp][WHITE], dp[temp][BLACK]);
			wtemp += dp[temp][BLACK];
		}
	}
	dp[now][BLACK] = btemp + 1;
	dp[now][WHITE] = wtemp;
	/*printf("XDD %d BLACK %d, WHITE %d.\n", now, dp[now][BLACK], dp[now][WHITE]);*/
}

int main()
{
	int n, i, p, q;
	while(scanf("%d", &n) == 1)
	{
		memset(num, 0, sizeof(num));
		for(i=1; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			map[p][num[p]++] = q;
			map[q][num[q]++] = p;
		}
		recursion(1, 0);
		printf("%d\n", min(dp[1][WHITE], dp[1][BLACK]));
	}
	return 0;
}
