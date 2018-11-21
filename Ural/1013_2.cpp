#include <stdio.h>
#include <string.h>

#define BASE 100000

int used[200][20], dp[1820][20][2][380], temp[380], len[1820][20][2], tlen;

void getnum(int n, int k)
{
	int i;
	memset(temp, 0, sizeof(temp));
	for(i=0; i<len[n][k][1]; i++)
	{
		temp[i] += dp[n][k][0][i] + dp[n][k][1][i];
		if(temp[i] >= BASE)
		{
			temp[i+1] = 1;
			temp[i] -= BASE;
		}
	}
	if(temp[i])
	{
		i++;
	}
	tlen = i;
}

void calc(int n, int k)
{
	int i;
	if(used[n][k])
	{
		return;
	}
	used[n][k] = 1;
	if(n == 1)
	{
		dp[n][k][0][0] = 0;
		len[n][k][0] = 1;
		dp[n][k][1][0] = k-1;
		len[n][k][1] = 1;
		return;
	}
	calc(n-1, k);
	memcpy(dp[n][k][0], dp[n-1][k][1], len[n-1][k][1]*sizeof(int));
	len[n][k][0] = len[n-1][k][1];
	getnum(n-1, k);
	for(i=0; i<tlen; i++)
	{
		dp[n][k][1][i] += temp[i] * (k-1);
		if(dp[n][k][1][i] >= BASE)
		{
			dp[n][k][1][i+1] = dp[n][k][1][i] / BASE;
			dp[n][k][1][i] %= BASE;
		}
	}
	len[n][k][1] = tlen;
	if(dp[n][k][1][i])
	{
		len[n][k][1]++;
	}
}

int main()
{
	int n, k, i;
	while(scanf("%d%d", &n, &k) == 2)
	{
		calc(n, k);
		getnum(n, k);
		printf("%d", temp[tlen-1]);
		for(i=tlen-2; i>=0; i--)
		{
			printf("%05d", temp[i]);
		}
		printf("\n");
	}
	return 0;
}
